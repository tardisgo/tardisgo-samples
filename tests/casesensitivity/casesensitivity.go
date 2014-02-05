package main

import "github.com/tardisgo/tardisgo/tardisgolib"

func TEQ(l string, a, b interface{}) bool {
	if a != b {
		println("TEQ error " + l + " ")
		println(a)
		println(b)
		return false
	}
	return true
}
func Sqrt(x float64) float64 {
	z := x
	for i := 0; i < 1000; i++ {
		z -= (z*z - x) / (2.0 * x)
	}
	return z
}

// these two names were failing in java as being duplicates, now failing in PHP...
func Ilogb(x float64) int {
	return int(Sqrt(x)) - 42
}
func ilogb(x float64) int {
	return int(Sqrt(x)) - 42
}
func testCaseSensitivity() {
	TEQ(tardisgolib.CPos(), ilogb(64), Ilogb(64))
}
func main() {
	testCaseSensitivity()
}
