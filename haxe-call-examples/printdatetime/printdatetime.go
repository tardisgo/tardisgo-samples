package main

import (
	// Each of the two definition files below should work
	//. "github.com/tardisgo/tardisgo-samples/haxe-call-examples/printdatetime/_defs" // hand-created defs
	. "github.com/tardisgo/gohaxelib/_cross" // API auto-generated defs

	"github.com/tardisgo/tardisgo/tardisgolib"
	"github.com/tardisgo/tardisgo/tardisgolib/hx"
)

// Print current Haxe date and time using the Haxe "target".Lib.println() API if one exists
func main() {

	dateNow := XDate_now_0() // or hx.CallDynamic("", "Date.now", 0)

	sDate := dateNow.XtoString_0() // or hx.MethString("", dateNow, "Date", "toString", 0)

	fTime := dateNow.XgetTime_0() // or hx.MethFloat("", dateNow, "Date", "getTime", 0)

	sTime := hx.CallString("", "Std.string", 1, fTime)

	s := tardisgolib.Platform() + " says it is " + sDate + "; timestamp= " + sTime

	switch tardisgolib.Platform() {
	case "neko", "cpp", "php":
		hx.Call("neko", "neko.Lib.println", 1, s)
		hx.Call("cpp", "cpp.Lib.println", 1, s)
		hx.Call("php", "php.Lib.println", 1, s)

	default:
		// print using the built-in trace-style println() for other platforms
		println(s)
	}

	pit("42")
	pit("garbage")
}

func pit(s string) { // showing how to handle Haxe return values that may be null
	x := XStd_parseInt_1(s)
	if x == nil {
		println("invalid integer")
	} else {
		println(x.(int))
	}
}
