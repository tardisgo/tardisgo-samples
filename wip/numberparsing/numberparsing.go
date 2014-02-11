// Parsing numbers from strings is a basic but common task
// in many programs; here's how to do it in Go.

package main

// The built-in package `strconv` provides the number
// parsing.
import "strconv"

//import "fmt"

func main() {

	// With `ParseFloat`, this `64` tells how many bits of
	// precision to parse.
	f, err := strconv.ParseFloat("1.234", 64)
	if err == nil {
		println(f)
	} else {
		println(err.Error())
	}

	println(strconv.IntSize)
	println(cutoff64(32))

	// For `ParseInt`, the `0` means infer the base from
	// the string. `64` requires that the result fit in 64
	// bits.
	i, err := strconv.ParseInt("123", 0, 32) // was 64)
	if err == nil {
		println(i)
	} else {
		println(err.Error())
	}
	println(strconv.FormatInt(i, 10))

	// `ParseInt` will recognize hex-formatted numbers.
	d, err := strconv.ParseInt("0x1c8", 0, 32) // was 64)
	if err == nil {
		println(d)
	} else {
		println(err.Error())
	}
	println(strconv.FormatInt(d, 10))

	// A `ParseUint` is also available.
	u, err := strconv.ParseUint("789", 0, 32) // was 64)
	if err == nil {
		println(u)
	} else {
		println(err.Error())
	}
	println(strconv.FormatUint(u, 10))

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

func cutoff64(base int) uint64 {
	if base < 2 {
		return 0
	}
	println("uint64(1<<64 - 1)=", uint64(1<<64-1))
	println("uint64(base)=", uint64(base))
	println("uint64(0xffffffff)/uint64(base) + 1=", uint64(0xffffffff)/uint64(base)+1)
	println("uint(0xffffffff)/uint(base) + 1=", uint(0xffffffff)/uint(base)+1)
	return (1<<64-1)/uint64(base) + 1
}
