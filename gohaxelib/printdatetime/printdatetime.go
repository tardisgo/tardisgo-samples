package main

import (
	"github.com/tardisgo/gohaxelib/_haxeapi"
	"github.com/tardisgo/tardisgo/tardisgolib"
)

// Print current Haxe date and time using the Haxe "target".Lib.println() API if one exists
func main() {

	dateNow := _haxeapi.XDate_now()

	sDate := dateNow.XtoString()

	fTime := dateNow.XgetTime()

	sTime := _haxeapi.XStd_string(fTime)

	s := tardisgolib.Platform() + " says it is " + sDate + "; timstamp= " + sTime

	switch tardisgolib.Platform() {
	case "neko":
		_haxeapi.Nneko_Lib_println(s)

	case "cpp":
		_haxeapi.Pcpp_Lib_println(s)

	case "php":
		_haxeapi.Hphp_Lib_println(s)

	default:
		// print using the built-in trace-style println() for other platforms
		println(s)
	}

}
