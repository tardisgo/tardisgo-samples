// test code for an error report yet to be made...

package main

import (
	"fmt"
	"go/build"
	"os"
	"strings"

	"golang.org/x/tools/go/loader"
	"golang.org/x/tools/go/ssa"
	"golang.org/x/tools/go/types"
)

func main() {
	if err := doMain(); err != nil {
		fmt.Fprintf(os.Stderr, "error: %s\n", err)
		os.Exit(1)
	}
	os.Exit(0)
}

func doMain() error {
	err := doTestable(false)
	if err == nil {
		err = doTestable(true)
	}
	return err
}

func doTestable(alterGOROOT bool) error {

	conf := loader.Config{
		Build:            &build.Default,
		ImportFromBinary: false,
	}

	var wordSize int64 = 4 // TARDIS Go addition to force default int size to 32 bits

	conf.Build.BuildTags = []string{}

	conf.TypeChecker.Sizes = &types.StdSizes{ // must equal haxeStdSizes when (!*runFlag)
		MaxAlign: 8,
		WordSize: wordSize,
	}

	var mode ssa.BuilderMode

	if alterGOROOT { // can only make if fail when using tardisgo versions of the std libs - doh!
		conf.Build.GOROOT = strings.Split(conf.Build.GOPATH, ":")[0] + "/src/github.com/tardisgo/tardisgo/goroot/haxe/go1.4"
		conf.Build.GOARCH = "haxe"
		conf.Build.GOOS = "nacl"
	}
	fmt.Println("DEBUG conf.Build.GOROOT=", conf.Build.GOROOT)

	importPath := "github.com/tardisgo/tardisgo-samples/errors/examplepanic/errors"

	fmt.Println("DEBUG importPath=", importPath)

	conf.ImportWithTests(importPath)

	// Load, parse and type-check the whole program.
	iprog, err := conf.Load()
	if err != nil {
		return err
	}

	// Create and build SSA-form program representation.
	prog := ssa.Create(iprog, mode)

	prog.BuildAll()

	var main *ssa.Package
	pkgs := prog.AllPackages()
	if len(pkgs) > 0 {
		main = prog.CreateTestMainPackage(pkgs...)
	}
	if main == nil {
		return fmt.Errorf("no tests")
	}
	fmt.Println("DEBUG created test func=", main.String())
	return nil
}
