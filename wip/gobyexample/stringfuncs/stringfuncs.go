// The standard library's `strings` package provides many
// useful string-related functions. Here are some examples
// to give you a sense of the package.

package main // adapted from gobyexample.com

// TODO strings.split() function not working correctly in flash

import s "strings"

// required TARDIS Go runtime support for the strings go package
import _ "github.com/tardisgo/tardisgo/golibruntime/strings"

//import _ "github.com/tardisgo/tardisgo/golibruntime/tgosync"

//import _ "github.com/tardisgo/tardisgo/golibruntime/sync/atomic"
//import _ "github.com/tardisgo/tardisgo/golibruntime/runtime"

//import "fmt"

// We alias `fmt.Println` type functionality to a shorter name as we'll use
// it a lot below.
//var p = fmt.Println
func p(vs ...interface{}) {
	x := make([]interface{}, len(vs))
	for i, v := range vs {
		x[i] = v
	}
	switch len(vs) {
	case 0:
		println()
	case 2:
		println(x[0].(string), x[1])
	}
}

func main() {
	// Here's a sample of the functions available in
	// `strings`. Note that these are all functions from
	// package, not methods on the string object itself.
	// This means that we need pass the string in question
	// as the first argument to the function.
	p("Contains:  ", s.Contains("test", "es"))
	p("Count:     ", s.Count("test", "t"))
	p("HasPrefix: ", s.HasPrefix("test", "te"))
	p("HasSuffix: ", s.HasSuffix("test", "st"))
	p("Index:     ", s.Index("test", "e"))
	p("Join:      ", s.Join([]string{"a", "b"}, "-"))
	p("Repeat:    ", s.Repeat("a", 5))
	p("Replace:   ", s.Replace("foo", "o", "0", -1))
	p("Replace:   ", s.Replace("foo", "o", "0", 1))
	p("Split:     ", s.Split("a-b-c-d-e", "-"))
	p("ToLower:   ", s.ToLower("TEST"))
	p("ToUpper:   ", s.ToUpper("test"))
	p()

	// You can find more functions in the [`strings`](http://golang.org/pkg/strings/)
	// package docs.

	// Not part of `strings` but worth mentioning here are
	// the mechanisms for getting the length of a string
	// and getting a character by index.
	p("Len: ", len("hello"))
	p("Char:", "hello"[1])
}

/* Expected output:
Contains:   true
Count:      2
HasPrefix:  true
HasSuffix:  true
Index:      1
Join:       a-b
Repeat:     aaaaa
Replace:    f00
Replace:    f0o
Split:      [a b c d e]
ToLower:    test
ToUpper:    TEST

Len:  5
Char: 101
*/
