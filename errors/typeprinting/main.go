package main

import (
	"fmt"
	"go/build"
	"os"

	"golang.org/x/tools/go/loader"
	"golang.org/x/tools/go/ssa"
	"golang.org/x/tools/go/ssa/ssautil"
)

// E is a global for ease of access
var E struct {
	i interface{}
}

// F is an example function
func F(p int) {}

func main() {
	fmt.Printf("\nfmt (reflect) type descriptions:\nE = %T\nF = %T\n", E, F)

	conf := loader.Config{
		Build: &build.Default,
	}

	// Parse the input file.
	file, err := conf.ParseFile("main.go", nil)
	if err != nil {
		fmt.Print(err) // parse error
		return
	}
	// Create single-file main package.
	conf.CreateFromFiles("main", file)
	conf.Import("runtime")

	// Load the main package and its dependencies.
	iprog, err := conf.Load()
	if err != nil {
		fmt.Print(err) // type error in some package
		return
	}

	// Create SSA-form program representation.
	prog := ssautil.CreateProgram(iprog, ssa.SanityCheckFunctions)
	mainPkg := prog.Package(iprog.Created[0].Pkg)

	// Print out the package.
	fmt.Println("\ngolang.org/x/tools/go/types type descriptions:")
	mainPkg.WriteTo(os.Stdout)
}
