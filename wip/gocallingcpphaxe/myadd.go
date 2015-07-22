package main

import "C"

//export Myadd
func Myadd(a, b int) int {
	c := a + b
	println("myadd", a, "+", b, "=", c)
	return a + b
}
