// Adapted from example at http://godoc.org/golang.org/x/text/unicode/norm#example-Iter
package main

import (
	"bytes"
	"fmt"
	"unicode/utf8"

	"golang.org/x/text/unicode/norm"
)

// EqualSimple uses a norm.Iter to compare two non-normalized
// strings for equivalence.
func EqualSimple(a, b string) bool {
	var ia, ib norm.Iter
	ia.InitString(norm.NFKD, a)
	ib.InitString(norm.NFKD, b)
	for !ia.Done() && !ib.Done() {
		if !bytes.Equal(ia.Next(), ib.Next()) {
			return false
		}
	}
	return ia.Done() && ib.Done()
}

// FindPrefix finds the longest common prefix of ASCII characters
// of a and b.
func FindPrefix(a, b string) int {
	i := 0
	for ; i < len(a) && i < len(b) && a[i] < utf8.RuneSelf && a[i] == b[i]; i++ {
	}
	return i
}

// EqualOpt is like EqualSimple, but optimizes the special
// case for ASCII characters.
func EqualOpt(a, b string) bool {
	n := FindPrefix(a, b)
	a, b = a[n:], b[n:]
	var ia, ib norm.Iter
	ia.InitString(norm.NFKD, a)
	ib.InitString(norm.NFKD, b)
	for !ia.Done() && !ib.Done() {
		if !bytes.Equal(ia.Next(), ib.Next()) {
			return false
		}
		if n := int64(FindPrefix(a[ia.Pos():], b[ib.Pos():])); n != 0 {
			ia.Seek(n, 1)
			ib.Seek(n, 1)
		}
	}
	return ia.Done() && ib.Done()
}

var compareTests = []struct{ a, b string }{
	{"aaa", "aaa"},
	{"aaa", "aab"},
	{"a\u0300a", "\u00E0a"},
	{"a\u0300\u0320b", "a\u0320\u0300b"},
	{"\u1E0A\u0323", "\x44\u0323\u0307"},
	// A character that decomposes into multiple segments
	// spans several iterations.
	{"\u3304", "\u30A4\u30CB\u30F3\u30AF\u3099"},
}

func main() {
	for i, t := range compareTests {
		r0 := EqualSimple(t.a, t.b)
		r1 := EqualOpt(t.a, t.b)
		fmt.Printf("%d: %s %v == %s %v ? Simple= %v Opt= %v\n",
			i, t.a, []byte(t.a), t.b, []byte(t.b), r0, r1)
	}
}
