// the classic hello world, using fmt - currenly a long way from working!
package main

import (
	"fmt"
	"strconv"

	"github.com/tardisgo/tardisgo/haxe/hx"
)

func main() {
	println(hx.GetBool("", "Object.nativeFloats"))
	minusZero := float64(float64(-1.0) * float64(0.0))
	minusZero32 := float32(float32(-1.0) * float32(0.0))
	fmt.Printf("Simple Hello World!")
	fmt.Printf("Hello %s : %d %g %g %v %T\n", "Elliott",
		-42, float32(42.42), float64(42.42), 42+42i, byte(0))
	println("42.42=", 42.42)
	println("strconv version:", strconv.FormatFloat(42.42, byte('g'), -1, 64))
	fmt.Printf("Hello %s : %d %g %g %v %T\n", " float64(float64(-1.0) * float64(0.0))",
		1, float32(minusZero32), float64(minusZero), minusZero, rune(0))
	println("Haxe native float64(float64(-1.0) * float64(0.0) ):", hx.CallString("", "Std.string", 1, minusZero))

	println("smallest f32 (1e-45)=", 1e-45)
	println("largest f64 (1.7976931348623157e+308)=", 1.7976931348623157e+308)

	//ptr := uintptr(0)
	//println(*(*int)(unsafe.Pointer(ptr)))
}
