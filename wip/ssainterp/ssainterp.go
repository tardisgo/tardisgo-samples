// Copyright 2013 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package main

import (
	"flag"
	"fmt"
	"go/build"
	"log"
	"os"
	"runtime"
	"runtime/pprof"
	"time"

	"github.com/tardisgo/tardisgo-samples/wip/ssainterp/interp"
	"golang.org/x/tools/go/loader"
	"golang.org/x/tools/go/ssa"
	"golang.org/x/tools/go/ssa/ssautil"
	"golang.org/x/tools/go/types"
)

var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to file")

// This program demonstrates how to run the SSA builder on a "Hello,
// World!" program and shows the printed representation of packages,
// functions and instructions.
//
// Within the function listing, the name of each BasicBlock such as
// ".0.entry" is printed left-aligned, followed by the block's
// Instructions.
//
// For each instruction that defines an SSA virtual register
// (i.e. implements Value), the type of that value is shown in the
// right column.
//
// Build and run the ssadump.go program if you want a standalone tool
// with similar functionality. It is located at
// golang.org/x/tools/cmd/ssadump.
//

func main() {
	flag.Parse()
	const hello = `
package main
import "runtime"
import "unsafe"
import "fmt"
import "os"
import b64 "encoding/base64"
//import "io/ioutil"
import "text/scanner"	

func b64main() {

	// Here's the string we'll encode/decode.
	data := "abc123!?$*&()'-=@~"

	// Go supports both standard and URL-compatible
	// base64. Here's how to encode using the standard
	// encoder. The encoder requires a []byte so we
	// cast our string to that type.
	sEnc := b64.StdEncoding.EncodeToString([]byte(data))
	println(sEnc)

	// Decoding may return an error, which you can check
	// if you don't already know the input to be
	// well-formed.
	sDec, _ := b64.StdEncoding.DecodeString(sEnc)
	println(string(sDec))
	println(" ") // TODO fix this bug - println() generates a haxe error : Unexpected )

	// This encodes/decodes using a URL-compatible base64
	// format.
	uEnc := b64.URLEncoding.EncodeToString([]byte(data))
	println(uEnc)
	uDec, _ := b64.URLEncoding.DecodeString(uEnc)
	println(string(uDec))
}

const message = "Testing, testing, 1... 2... 3..."

func Foo(a,b int) int 

var zero = 0

func fact(n int) int {
	//println("fact",n)
	if n == 0 {
		return 1
	}
	return n * fact(n-1)
}

func mandelbrot(n int) int {
	const Iter = 50
	const Zero float64 = 0
	const Limit = 2.0
	ok := 0
	for y := 0; y < n; y++ {
		for x := 0; x < n; x++ {
			Zr, Zi, Tr, Ti := Zero, Zero, Zero, Zero
			Cr := (2*float64(x)/float64(n) - 1.5)
			Ci := (2*float64(y)/float64(n) - 1.0)

			for i := 0; i < Iter && (Tr+Ti <= Limit*Limit); i++ {
				Zi = 2*Zr*Zi + Ci
				Zr = Tr - Ti + Cr
				Tr = Zr * Zr
				Ti = Zi * Zi
			}

			if Tr+Ti <= Limit*Limit {
				ok++
			}
		}
	}
	return ok
}

var testGlobal int = -72
var testStruct scanner.Position

type xT struct {
	a,b int
}

type yT struct {
	c,d xT
}

func main() {
	println(message)
    fmt.Printf("Hello %v/%v\n", runtime.GOOS, runtime.GOARCH)
	mol := fmt.Sprintf("The meaning of life the universe and everything is %d",42)
	println(mol)
	u := uintptr(42)
	println("The size of a uintptr is ", unsafe.Sizeof(u))
	println(Foo(1,2))
	println("ten factorial is ", fact(10)) // NOTE fmt package not implemented in TARDIS Go as at Jan'14
	x := float64(0)
	for i:=0;i<1000; i++ {
		x += float64(fact(i))
	}
	fmt.Printf("grand total is %v:%T\n",x,x)
	for i:= 0 ; i<10 ; i++ {
		b64main()
	}
	//buf,err:= ioutil.ReadFile("ssainterp.go")
	//println("ReadFile ",len(buf),err)
	fmt.Println("testing,testing",1,2,3)
	println(testGlobal)
	testGlobal = 8080
	println(testGlobal)	
	println(mandelbrot(1000)) //benchmark speed when fast enough...
	testStruct = scanner.Position{
		Filename: "ZombieApocolypse",
        Offset: 0,
        Line: 1,
        Column: 2, 
	}
	testStruct.Filename+="!"
	testStruct.Offset++
	testStruct.Line++
	testStruct.Column++
	println(testStruct.Filename,testStruct.Offset,testStruct.Line,testStruct.Column)
	fmt.Fprintf(os.Stdout, "PRINTed via os.Stdout %#v\n",testStruct)
	z := yT{xT{1,2},xT{3,4}}
	fmt.Printf("z initialized=%#v\n",z)
	twotwo := &z.c.b
	fmt.Println("*twotwo=",*twotwo)
	z.c = xT{5,6}
	fmt.Printf("z altered=%#v\n",z)
	fmt.Println("*twotwo=",*twotwo)
}
`

	conf := loader.Config{
		Build: &build.Default,
	}
	if runtime.GOOS == "linux" { // for testing in docker
		conf.Build.GOROOT = "/usr/src/go"
	}

	/* for running on TATDISgo, but does not work as too big
	syscall.UnzipFS("Users.zip") // call only exists on TARDISgo
	conf.Build.GOROOT = "/Users/elliott/go/src/github.com/tardisgo/tardisgo/goroot/haxe/go1.4/"
	conf.Build.GOPATH = "/Users/elliott/go/"
	conf.Build.GOOS = "nacl"
	conf.Build.GOARCH = "haxe"
	*/
	//conf.Build.GOOS = "nacl"
	//conf.Build.GOARCH = "386"

	println("Compiler:", runtime.Compiler)

	// Parse the input file.
	file, err := conf.ParseFile("hello.go", hello)
	if err != nil {
		fmt.Print(err) // parse error
		return
	}

	// Create single-file main package.
	conf.CreateFromFiles("main", file)
	conf.Import("runtime") // always need this for ssa/interp

	// Load the main package and its dependencies.
	iprog, err := conf.Load()
	if err != nil {
		fmt.Print(err) // type error in some package
		return
	}

	// Create SSA-form program representation.
	prog := ssautil.CreateProgram(iprog, ssa.SanityCheckFunctions)

	var mainPkg *ssa.Package
	for _, pkg := range prog.AllPackages() {
		if pkg.Object.Name() == "main" {
			mainPkg = pkg
			if mainPkg.Func("main") == nil {
				panic(fmt.Errorf("no func main() in main package"))
			}
			break
		}
	}
	if mainPkg == nil {
		panic(fmt.Errorf("no main package"))
	}

	// Build SSA code for bodies for whole program
	prog.BuildAll()

	mainPkg.Func("main").WriteTo(os.Stdout)

	if *cpuprofile != "" {
		f, err := os.Create(*cpuprofile)
		if err != nil {
			log.Fatal(err)
		}
		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()
	}

	exts := interp.NewExternals()
	exts.AddExtFunc("main.Foo", func(args []interp.Ivalue) interp.Ivalue {
		return args[0].(int) + args[1].(int)
	})
	/*
		exts.AddExtFunc("fmt.Println", func(args []interp.Ivalue) interp.Ivalue {
			fmt.Println(interp.IvalIfaceSlice(args[0].([]interp.Ivalue))...)
			return nil
		})
		exts.AddExtFunc("fmt.Printf", func(args []interp.Ivalue) interp.Ivalue {
			fmt.Printf(args[0].(string),
				interp.IvalIfaceSlice(args[1].([]interp.Ivalue))...)
			return nil
		})
		exts.AddExtFunc("fmt.Sprintf", func(args []interp.Ivalue) interp.Ivalue {
			return fmt.Sprintf(args[0].(string),
				interp.IvalIfaceSlice(args[1].([]interp.Ivalue))...)
		})
		exts.AddExtFunc("fmt.Fprintf", func(args []interp.Ivalue) interp.Ivalue {
			n, err := fmt.Fprintf(
				interp.IvalIface(args[0]).(*os.File), args[1].(string),
				interp.IvalIfaceSlice(args[2].([]interp.Ivalue))...)
			return []interp.Ivalue{n, err}
		})
		exts.AddExtGlob("os.Stdout", reflect.ValueOf(&os.Stdout))
		myPretendGlobal := 2424
		exts.AddExtGlob("main.testGlobal", reflect.ValueOf(&myPretendGlobal))
		myGlobalStruct := scanner.Position{"The Moon in June", 9, 8, 7}
		exts.AddExtGlob("main.testStruct", reflect.ValueOf(&myGlobalStruct))
	*/

	start := time.Now()
	ctxt, _ := interp.Interpret(mainPkg, 0, &types.StdSizes{8, 8}, "hello.go", []string{}, exts)
	fmt.Println("Time taken: ", time.Since(start))

	fmt.Println("context call fact(10)=", ctxt.Call("main.fact", []interp.Ivalue{int(10)}))
}
