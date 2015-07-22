package main

import "fmt"
import "github.com/tardisgo/tardisgo/haxe/hx"
import "runtime"

func main() {
	val := hx.CodeInt("cpp", `Gogo.get();`)
	//val := hx.CodeInt("cpp", `untyped __cpp__('666');`)
	fmt.Printf("Hello World from TARDIS Go, the meaning of life is %v\n", val)
	hx.Code("cpp", "Gogo.set(_a.param(0).val);",
		val+hx.CallInt("cpp", "Gogo.add", 2, 111, 222))

	gogoT := hx.CallDynamic("cpp", "Type.resolveClass", 1, "Gogo")
	println("gogoT=", gogoT)
	rv := hx.CodeInt("cpp", "Reflect.callMethod(_a.param(0).val,_a.param(1).val,[8,9]);",
		gogoT, "add")
	fmt.Printf("And the add numer is %d\n", rv)

	i := hx.CallInt("cpp", "Gohaxecpp.Int2Dynamic", 1, 42)
	println("Int2Dynamic=", i)

	go doStuff()
}

func doStuff() {
	for true {
		fmt.Println("doStuff")
		runtime.Gosched()
	}
}
