// Copyright 2015 Elliott Stoneham
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file.

// Some code below:
// Copyright 2013 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package main

import (
	"flag"
	"fmt"
	"go/build"
	"go/token"
	"os"
	"runtime"
	"runtime/pprof"
	"strings"
	"sync"
	"unicode"

	"golang.org/x/tools/go/callgraph"
	"golang.org/x/tools/go/loader"
	"golang.org/x/tools/go/pointer"
	"golang.org/x/tools/go/ssa"
	"golang.org/x/tools/go/ssa/ssautil"
	"golang.org/x/tools/go/types"
)

var debugFlag = flag.Bool("debug", false, "Instrument the code to enable debugging, add comments, and give more meaningful information during a stack dump (warning: increased code size)")
var buidTags = flag.String("tags", "", "build tags separated by spaces")

var prefix = flag.String("prefix", "", "inspect package level names with the given prefix")

var nonExp = flag.Bool("nonexp", false, "also look for unused non-exported names")
var namedConst = flag.Bool("namedconst", false, "also look at named constants (unreliable)")

var modeFlag = ssa.BuilderModeFlag(flag.CommandLine, "build", 0)

const cmdusage = `shouldexp suggests exported names in packages that maybe should not be exported 
Usage: shouldexp <mainpackage>
Use -help to display other options.
`

var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to file")

func main() {
	if err := doMain(); err != nil {
		fmt.Fprintf(os.Stderr, "error: %s\n", err)
		os.Exit(1)
	}
	os.Exit(0)
}

func setup() ([]string, error) {
	flag.Parse()
	args := flag.Args()
	if len(args) == 0 {
		return nil, fmt.Errorf("%v", cmdusage)
	}
	// Profiling support.
	if *cpuprofile != "" {
		f, err := os.Create(*cpuprofile)
		if err != nil {
			return nil, err
		}
		err = pprof.StartCPUProfile(f)
		if err != nil {
			return nil, err
		}
		defer pprof.StopCPUProfile()
	}
	if *debugFlag {
		*modeFlag |= ssa.GlobalDebug
	}
	*modeFlag |= ssa.SanityCheckFunctions
	return args, nil
}

func doMain() error {

	args, err := setup()
	if err != nil {
		return err
	}

	prog, pkgs, mainPkg, err := buildSSA(false, args)
	if err != nil {
		return err
	}

	if *prefix == "" {
		*prefix = args[0]
	}

	config := &pointer.Config{
		Mains:          mainPkg,
		BuildCallGraph: true,
		Reflection:     true,
	}
	ptrResult, err := pointer.Analyze(config)
	if err != nil {
		return err
	}
	//fmt.Println("number of pointer analysis warnings:", len(ptrResult.Warnings))

	// but pointer analysis only fully works when the "reflect" and "unsafe" packages are not used
	for _, pkg := range pkgs {
		switch pkg.Pkg.Name() {
		case "reflect", "unsafe", "C":
			fmt.Println("*** be cautious, pointer analysis is suspect because program uses package: " + pkg.Pkg.Name())
		}
	}

	showResults(prog, pkgs, ptrResult)

	return nil
}

var gopath string

func showResults(prog *ssa.Program, pkgs []*ssa.Package, ptrResult *pointer.Result) {
	defer wg.Wait()

	gopath, _ = os.LookupEnv("GOPATH")

	wg.Add(1)
	go func() {
		var globals map[ssa.Value]usage
		var gwg sync.WaitGroup
		defer wg.Done()

		gwg.Add(1)
		go func() {
			globals = getGlobs(pkgs)
			gwg.Done()
		}()
		typelist, typemap := getTypes(pkgs)
		gwg.Wait()

		if err := visitGraph(ptrResult, globals, typemap); err != nil {
			fmt.Println("error visiting graph:", err)
			return
		}

		wg.Add(1)
		go func() {
			for val := range globals {
				checkGlob(val, prog, globals)
			}
			wg.Done()
		}()

		for _, typ := range typelist {
			checkType(typ, prog, typemap)
		}
	}()

	roots, isRoot := getRoots(pkgs)
	for _, pkg := range pkgs {
		funcs := getFuncs(prog, pkg)
		for _, fn := range funcs {
			if fn != nil && !isRoot[fn] {
				wg.Add(1)
				go checkFn(fn, prog, ptrResult, roots)
			}
		}
	}
}

var gMtx, tMtx sync.Mutex

func visitRand(edge *callgraph.Edge, rand *ssa.Value,
	globals map[ssa.Value]usage, typemap map[*types.Named]usage) {
	insPkg := ""
	_, isGlobal := (*rand).(*ssa.Global)
	_, isConst := (*rand).(*ssa.Const)
	if isGlobal || isConst {
		gMtx.Lock()
		if used, ok := globals[*rand]; ok {
			used.isUsed = true
			insPkg = strings.TrimPrefix(edge.Callee.Func.Pkg.String(), "package ")
			if used.pkg != insPkg {
				used.isUsedExt = true
			}
			globals[*rand] = used
		}
		gMtx.Unlock()
	}
	rT := (*rand).Type()
	rT = findNamed(rT)
	if rTn, isNamed := rT.(*types.Named); isNamed {
		tMtx.Lock()
		if used, ok := typemap[rTn]; ok {
			used.isUsed = true
			valPkg := used.pkg
			if insPkg == "" {
				ip := edge.Callee.Func.Pkg
				if ip != nil {
					insPkg = strings.TrimPrefix(ip.String(), "package ")
				}
			}
			if valPkg != insPkg {
				used.isUsedExt = true
			}
			typemap[rTn] = used
		}
		tMtx.Unlock()
	}
}

func visitGraph(ptrResult *pointer.Result, globals map[ssa.Value]usage, typemap map[*types.Named]usage) error {
	n := runtime.NumCPU()
	q := make(chan *callgraph.Edge, n)
	var vgwg sync.WaitGroup
	vgwg.Add(n)
	for i := 0; i < n; i++ {
		go func() {
			for edge := range q {
				for _, blk := range edge.Callee.Func.Blocks {
					for _, ins := range blk.Instrs {
						for _, rand := range ins.Operands(nil) {
							if rand != nil && *rand != nil {
								visitRand(edge, rand, globals, typemap)
							}
						}
					}
				}
			}
			vgwg.Done()
		}()
	}
	err := callgraph.GraphVisitEdges(ptrResult.CallGraph, func(edge *callgraph.Edge) error {
		if edge.Callee != nil {
			q <- edge
		}
		return nil
	})
	close(q)
	vgwg.Wait()
	return err
}

var wg sync.WaitGroup

func findNamed(typ types.Type) types.Type {
find:
	switch typ.(type) {
	// map?
	case *types.Pointer:
		typ = typ.(*types.Pointer).Elem()
		goto find
	case *types.Slice:
		typ = typ.(*types.Slice).Elem()
		goto find
	case *types.Named:
		return typ
	}
	return nil
}

func checkType(typ *ssa.Type, prog *ssa.Program, typemap map[*types.Named]usage) {
	typT := findNamed(typ.Type())
	rec := typemap[typT.(*types.Named)]
	used := rec.isUsed || typ.Type().(*types.Named).NumMethods() > 0
	extUsed := rec.isUsedExt
	isUpper := rec.isCap
	loc := strings.TrimPrefix(
		prog.Fset.Position(typ.Pos()).String(),
		gopath+"/src/"+*prefix+"/")
	nam := strings.TrimPrefix(typ.String(), *prefix)
	nam = strings.TrimPrefix(nam, ".")
	nam = strings.TrimPrefix(nam, "/")
	if !used {
		fmt.Println(loc, "warning: type", nam, "may not be used, consider removing")
		return
	}
	if isUpper && !extUsed {
		fmt.Println(loc, "warning: type", nam, "may not be used externally, consider de-capitalizing")
	}
}

func checkGlob(val ssa.Value, prog *ssa.Program, globmap map[ssa.Value]usage) {
	used := globmap[val].isUsed
	extUsed := globmap[val].isUsedExt
	isUpper := globmap[val].isCap
	pos := globmap[val].pos
	var class string
	switch val.(type) {
	case *ssa.Global:
		class = "global"
	case *ssa.Const:
		class = "constant"
	}
	loc := strings.TrimPrefix(
		prog.Fset.Position(pos).String(),
		gopath+"/src/"+*prefix+"/")
	valS := strings.TrimPrefix(globmap[val].pkg+"."+globmap[val].str, *prefix)
	valS = strings.TrimPrefix(valS, ".")
	valS = strings.TrimPrefix(valS, "/")
	if !used {
		fmt.Println(loc, "warning:", class, valS, "may not be used, consider removing")
		return
	}
	if !extUsed && isUpper {
		fmt.Println(loc, "warning:", class, valS, "may not be used externally, consider de-capitalizing")
	}
}

func checkFn(fn *ssa.Function, prog *ssa.Program, ptrResult *pointer.Result, roots []*ssa.Function) {
	nam := fn.String()
	if strings.HasPrefix(strings.TrimPrefix(nam, "("), *prefix) {
		hasPath := false
		usedExternally := false
		for _, r := range roots {
			if r != nil {
				nod, ok := ptrResult.CallGraph.Nodes[r]
				if ok {
					//fmt.Println("NODE root", r.Name())
					pth := callgraph.PathSearch(nod,
						func(n *callgraph.Node) bool {
							if n == nil {
								return false
							}
							if n.Func == fn {
								for _, ine := range n.In {
									if ine.Caller.Func.Pkg != fn.Pkg {
										//fmt.Println("DEBUG diff? ",
										//	ine.Caller.Func.Pkg, fn.Pkg)
										usedExternally = true
										break
									}
								}
								return true
							}
							return false
						})
					if pth != nil {
						//fmt.Printf("DEBUG path from %v to %v = %v\n",
						//	r, fn, pth)
						hasPath = true
						break
					}
				}
			}
		}
		isUpper := unicode.IsUpper(rune(fn.Name()[0]))
		pos := fn.Pos()
		//if strings.HasPrefix(nam, "(") && (!hasPath || (!usedExternally && isUpper)) {
		//	fmt.Println("bad Pos", pos, prog.Fset.Position(pos).String())
		//}
		loc := strings.TrimPrefix(
			prog.Fset.Position(pos).String(),
			gopath+"/src/"+*prefix+"/")
		showFuncResult(loc, nam, hasPath, usedExternally, isUpper)
	}
	wg.Done()
}

func showFuncResult(loc, nam string, hasPath, usedExternally, isUpper bool) {
	if strings.HasPrefix(nam, "(") {
		loc = "" // doesn't get the location of methods correct
		nam = "(" + strings.TrimPrefix(nam, "("+*prefix+"/")
	} else {
		loc = strings.TrimPrefix(loc, *prefix+"/")
		nam = strings.TrimPrefix(nam, *prefix)
	}
	nam = strings.TrimPrefix(nam, ".")
	nam = strings.TrimPrefix(nam, "/")
	if !hasPath {
		fmt.Println(loc, "warning: func", nam,
			"may not be called, consider removing")
		return
	}
	if !usedExternally && isUpper {
		fmt.Println(loc, "warning: func", nam,
			"may only be used internally, consider de-capitalizing")
	}
}

func getRoots(pkgs []*ssa.Package) ([]*ssa.Function, map[*ssa.Function]bool) {
	roots := make([]*ssa.Function, len(pkgs))
	isRoot := make(map[*ssa.Function]bool)
	for _, pkg := range pkgs {
		if pkg != nil {
			for _, mem := range pkg.Members {
				fn, ok := mem.(*ssa.Function)
				if ok { // TODO - not hard-coded values, more descrimination
					if (pkg.Pkg.Name() == "main" && fn.Name() == "main") ||
						pkg.String() == "package test$main" ||
						strings.HasPrefix(fn.Name(), "init") {
						roots = append(roots, fn)
						isRoot[fn] = true
						//fmt.Println("DEBUG root added:", fn.String())
					}
				}
			}
		}
	}
	return roots, isRoot
}

func getFuncs(prog *ssa.Program, pkg *ssa.Package) []*ssa.Function {
	funcs := make([]*ssa.Function, 0, len(pkg.Members))
	for _, mem := range pkg.Members {
		fn, ok := mem.(*ssa.Function)
		if ok {
			if iu := unicode.IsUpper(rune(fn.Name()[0])); iu || *nonExp {
				funcs = append(funcs, fn)
			}
		}
		typ, ok := mem.(*ssa.Type)
		if ok {
			mset := prog.MethodSets.MethodSet(typ.Type())
			for i, n := 0, mset.Len(); i < n; i++ {
				if mf := prog.MethodValue(mset.At(i)); mf != nil {
					if mfn := mf.Name(); len(mfn) > 0 {
						if iu := unicode.IsUpper(rune(mfn[0])); iu || *nonExp {
							funcs = append(funcs, mf)
							//fmt.Printf("DEBUG method %v %v\n", mfn, mf)
						}
					}
				}
			}
		}
	}
	return funcs
}

type usage struct {
	isCap, isUsed, isUsedExt bool
	pkg, str                 string
	pos                      token.Pos
}

func getGlobs(pkgs []*ssa.Package) map[ssa.Value]usage {
	vals := make(map[ssa.Value]usage)
	for _, pkg := range pkgs {
		if strings.HasPrefix(pkg.Pkg.Path(), *prefix) {
			for _, mem := range pkg.Members {
				if val, isVal := mem.(ssa.Value); isVal {
					switch val.(type) {
					case *ssa.Global:
						if iu := unicode.IsUpper(rune(val.Name()[0])); iu || *nonExp {
							vals[val] = usage{
								isCap: iu,
								pkg:   strings.Split(val.String(), ".")[0],
								str:   val.Name(),
								pos:   val.Pos(),
							}
						}
					}
				}
				/* not currently reliable */
				if *namedConst {
					switch m := mem.(type) {
					case *ssa.NamedConst:
						if iu := unicode.IsUpper(rune(mem.Name()[0])); iu || *nonExp {
							val := ssa.Value(m.Value)
							vals[val] = usage{
								isCap: iu,
								pkg:   strings.TrimPrefix(mem.Package().String(), "package "),
								str:   mem.Name(),
								pos:   mem.Pos(),
							}
						}
					}
				}
			}
		}
	}
	return vals
}

func getTypes(pkgs []*ssa.Package) ([]*ssa.Type, map[*types.Named]usage) {
	list := make([]*ssa.Type, 0, len(pkgs))
	vals := make(map[*types.Named]usage)
	for _, pkg := range pkgs {
		if strings.HasPrefix(pkg.Pkg.Path(), *prefix) {
			for _, mem := range pkg.Members {
				switch val := mem.(type) {
				case *ssa.Type:
					nt := findNamed(val.Type())
					if nt != nil {
						if iu := unicode.IsUpper(rune(val.Name()[0])); iu || *nonExp {
							vals[nt.(*types.Named)] = usage{
								isCap: iu,
								pkg:   strings.Split(val.String(), ".")[0],
							}
							list = append(list, val)
						}
					}
				}
			}
		}
	}
	return list, vals
}

func buildSSA(testFlag bool, args []string) (*ssa.Program, []*ssa.Package, []*ssa.Package, error) {

	conf := loader.Config{
		Build: &build.Default,
	}

	conf.Build.BuildTags = strings.Split(*buidTags, " ")

	//fmt.Println("DEBUG GOPATH", conf.Build.GOPATH)
	//fmt.Println("DEBUG GOROOT", conf.Build.GOROOT)

	if testFlag {
		conf.ImportWithTests(args[0]) // assumes you give the full cannonical name of the package to test
		args = args[1:]
	}

	// Use the initial packages from the command line.
	_, err := conf.FromArgs(args, testFlag)
	if err != nil {
		return nil, nil, nil, err
	}

	// Load, parse and type-check the whole program.
	iprog, err := conf.Load()
	if err != nil {
		return nil, nil, nil, err
	}

	// Create and build SSA-form program representation.
	prog := ssautil.CreateProgram(iprog, *modeFlag)

	prog.Build()

	pkgs := prog.AllPackages()
	//fmt.Println("DEBUG pkgs:", pkgs)

	main := make([]*ssa.Package, 0, 1)
	if testFlag {
		if len(pkgs) > 0 {
			main = append(main, prog.CreateTestMainPackage(pkgs...))
		}
		if len(main) == 0 {
			return nil, nil, nil, fmt.Errorf("no tests")
		}
		pkgs = append(pkgs, main...)
		//fmt.Println("Test main package created:", main)
		return prog, pkgs, main, nil
	}
	foundMain := false
	for _, pkg := range pkgs {
		if pkg.Pkg.Name() == "main" {
			if pkg.Func("main") == nil {
				return nil, nil, nil, fmt.Errorf("no func main() in main package")
			}
			main = append(main, pkg)
			foundMain = true
		}
		if foundMain {
			return prog, pkgs, main, nil
		}
	}
	fmt.Println("*** no main package found, using tests")
	return buildSSA(true, args)
}
