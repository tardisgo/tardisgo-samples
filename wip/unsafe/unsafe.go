package main

import (
	"fmt"
	"unsafe"
)

type t struct {
	a int
	_ byte
	b string
}

func main() {

	// Create a slice of the correct size
	m := make([]int, 1)

	// Use convoluted indirection to cast the first few bytes of the slice
	// to an unsafe uintptr
	mPtr := (*int)(unsafe.Pointer(&m[0]))

	// Check it worked
	m[0] = 987
	// (we have to recast the uintptr to a *int to examine it)
	fmt.Println(m[0], mPtr, *(*int)(unsafe.Pointer(mPtr)))

	println("Test:", unsafe.Sizeof(0), unsafe.Sizeof(t{}), unsafe.Offsetof(t{}.b), unsafe.Alignof(t{}.b))
}
