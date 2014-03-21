package main

import (
	"github.com/tardisgo/gohaxelib/_haxeapi"
	"github.com/tardisgo/tardisgo/tardisgolib"
)

// Print tardisgo web site LICENSE in the simplest way possible
// (this particular formulation does not work for JavaScript, C# or Flash)
func main() {

	s := string(_haxeapi.Xhaxe_Http_requestUrl("http://tardisgo.github.io/LICENSE"))

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
