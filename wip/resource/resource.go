package main

import "github.com/tardisgo/tardisgo/haxe/hx"

func main() {
	names := hx.GetDynamic("", "haxe.Resource.listNames()")
	println(names)
	l := hx.FgetInt("", names, "", "length")
	println(l)
	for n := 0; n < l; n++ {
		nam := hx.MethString("", names, "", "shift", 0)
		println("FileName:" + nam)
		b := hx.Resource(nam)
		println(b)
		s := string(b)
		println(s)
	}
}
