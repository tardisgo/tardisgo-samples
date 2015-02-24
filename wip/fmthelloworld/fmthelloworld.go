// the classic hello world, using fmt - currenly a long way from working!
package main

import (
	"fmt"
	"strconv"
)

type s struct {
	b string
	a int
}

type t struct {
	s
	c string
}

func main() {
	//fmt.Printf("Hello %s : %d %g %g %v %T\n", "Elliott",
	//	-42, float32(42.42), float64(42.42), 42+42i, byte(0))
	println("haxe 42.42=", 42.42)
	println("strconv version:", strconv.FormatFloat(42.42, byte('g'), -1, 64))
	//println("Haxe native float64(float64(-1.0) * float64(0.0) ):", hx.CallString("", "Std.string", 1, minusZero))

	//println("smallest f32 (1e-45)=", 1e-45)
	//println("largest f64 (1.7976931348623157e+308)=", 1.7976931348623157e+308)

	//ptr := uintptr(0)
	//println(*(*int)(unsafe.Pointer(ptr)))

	var a = [2][5]float64{{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}}
	sl := a[1][1:4]
	fmt.Printf("The array a: %v %v\n", a, sl)

	var sl2 = [][]float64{{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}}
	fmt.Printf("The slice sl2: %v\n", sl2)

	var b = [5]string{"alpha", "beta", "gamma", "delta", "epislon"}
	fmt.Printf("The array b: %v %v\n", b, b[1:4])

	var c = [][]string{{"tulips", "from", "amsterdam"}, {"a", "fool", "on", "the", "hill"}}
	fmt.Printf("c[0]=%v\n", c[0])
	fmt.Printf("The slice of slices c: %v \n", c)

	itter := 0
	for u := uint64(1); itter < 53; u = u<<1 + 1 {
		f := float64(u)
		fu := uint64(f)
		if u != fu {
			println("uint64/float64 conversion error", itter, u, f, fu, u == fu)
		}
		itter++
	}

	fmt.Printf("Struct: %v\n", t{s{"Level", 42}, "rocks"})

}
