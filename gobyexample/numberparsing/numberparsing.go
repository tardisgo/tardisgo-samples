// Parsing numbers from strings is a basic but common task
// in many programs; here's how to do it in Go.

package main

// The built-in package `strconv` provides the number
// parsing and printing.
import (
	_ "github.com/tardisgo/tardisgo/golibruntime/math" // required by strconv
	"strconv"
)

//import "fmt"

func main() {
	bitSize := 64

	// With `ParseFloat`, this `64` tells how many bits of
	// precision to parse.
	f, err := strconv.ParseFloat("1.234", bitSize)
	if err == nil {
		println(strconv.FormatFloat(f, 'f', -1, bitSize))
	} else {
		println(err.Error())
	}

	// For `ParseInt`, the `0` means infer the base from
	// the string. `64` requires that the result fit in 64
	// bits.
	i, err := strconv.ParseInt("123", 0, bitSize)
	if err == nil {
		println(strconv.FormatInt(i, 10))
	} else {
		println(err.Error())
	}

	// `ParseInt` will recognize hex-formatted numbers.
	d, err := strconv.ParseInt("0x1c8", 0, bitSize)
	if err == nil {
		println(strconv.FormatInt(d, 10))
	} else {
		println(err.Error())
	}

	// A `ParseUint` is also available.
	u, err := strconv.ParseUint("789", 0, bitSize)
	if err == nil {
		println(strconv.FormatUint(u, 10))
	} else {
		println(err.Error())
	}

	// `Atoi` is a convenience function for basic base-10
	// `int` parsing.
	k, err := strconv.Atoi("135")
	if err == nil {
		println(k)
	} else {
		println(err.Error())
	}

	// Parse functions return an error on bad input.
	_, e := strconv.Atoi("wat")
	println(e.Error())

}
