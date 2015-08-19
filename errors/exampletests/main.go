package main

import (
	"fmt"

	"golang.org/x/tools/go/loader"
	"golang.org/x/tools/go/ssa"
	"golang.org/x/tools/go/ssa/ssautil"
)

func main() {
	var conf loader.Config
	inputs := []string{"./bonzo"}

	if _, err := conf.FromArgs(inputs, true); err != nil {
		fmt.Printf("FromArgs(%s) failed: %s", inputs, err)
		return
	}

	conf.Import("runtime")

	iprog, err := conf.Load()
	if err != nil {
		fmt.Printf("conf.Load(%s) failed: %s", inputs, err)
		return
	}

	prog := ssautil.CreateProgram(iprog, ssa.SanityCheckFunctions)
	prog.BuildAll()

	var mainPkg *ssa.Package
	var initialPkgs []*ssa.Package
	for _, info := range iprog.InitialPackages() {
		if info.Pkg.Path() == "runtime" {
			continue // not an initial package
		}
		p := prog.Package(info.Pkg)
		initialPkgs = append(initialPkgs, p)
		if mainPkg == nil && p.Func("main") != nil {
			mainPkg = p
			fmt.Println("unexpexted main package in this bonzo example")
			return
		}
	}
	if mainPkg == nil {
		testmainPkg := prog.CreateTestMainPackage(initialPkgs...)
		if testmainPkg == nil {
			fmt.Printf("CreateTestMainPackage(%s) returned nil", mainPkg)
			return
		}
		if testmainPkg.Func("main") == nil {
			fmt.Printf("synthetic testmain package has no main")
			return
		}
		mainPkg = testmainPkg
	}

	fmt.Println("built:", mainPkg.String())
	for _, mem := range mainPkg.Members {
		if fn, isFn := mem.(*ssa.Function); isFn {
			printFunc(fn, 1)
		}
	}
}

func printFunc(fn *ssa.Function, depth int) {
	if depth == 0 {
		return
	}
	depth--
	printList := make(map[*ssa.Function]struct{})
	fmt.Println("\nfunction:", fn.String())
	for b, bl := range fn.Blocks {
		fmt.Printf("block %d:\n", b)
		for _, in := range bl.Instrs {
			if val, isVal := in.(ssa.Value); isVal {
				fmt.Println("\t", val.Name(), "=", in)
			} else {
				fmt.Println("\t", in)
			}
			for _, rand := range in.Operands(nil) {
				if called, isFn := (*rand).(*ssa.Function); isFn {
					printList[called] = struct{}{}
				}
			}
			if call, isCall := in.(*ssa.Call); isCall {
				sc := call.Call.StaticCallee()
				if sc != nil {
					printList[sc] = struct{}{}
				}
			}
		}
	}
	for called := range printList {
		printFunc(called, depth)
	}
}
