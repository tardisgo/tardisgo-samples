// The standard library's `strings` package provides many
// useful string-related functions. Here are some examples
// to give you a sense of the package.

package main // adapted from gobyexample.com

import s "strings"
import "fmt"

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
		fmt.Println()
	case 2:
		fmt.Println(x[0].(string), x[1])
	}
}

func main() {
	// Here's a sample of the functions available in
	// `strings`. Note that these are all functions from
	// package, not methods on the string object itself.
	// This means that we need pass the string in question
	// as the first argument to the function.
	p("Contains =true  ", s.Contains("test", "es"))
	p("Count =2        ", s.Count("test", "t"))
	p("HasPrefix =true ", s.HasPrefix("test", "te"))
	p("HasSuffix =true ", s.HasSuffix("test", "st"))
	p("Index =1        ", s.Index("test", "e"))
	p("Join =a-b       ", s.Join([]string{"a", "b"}, "-"))
	p("Repeat =aaaaa   ", s.Repeat("a", 5))
	p("Replace =f00    ", s.Replace("foo", "o", "0", -1))
	p("Replace =f0o    ", s.Replace("foo", "o", "0", 1))
	banana := s.Split("a-b-c-d-e", "-")
	p("Split 0=a       ", banana[0])
	p("Split 1=b       ", banana[1])
	p("Split 2=c       ", banana[2])
	p("Split 3=d       ", banana[3])
	p("Split 4=e       ", banana[4])
	p("ToLower =test   ", s.ToLower("TEST"))
	p("ToUpper =TEST   ", s.ToUpper("test"))
	p()

	// You can find more functions in the [`strings`](http://golang.org/pkg/strings/)
	// package docs.

	// Not part of `strings` but worth mentioning here are
	// the mechanisms for getting the length of a string
	// and getting a character by index.
	p("Len =5    ", len("hello"))
	p("Char =101 ", "hello"[1])
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
