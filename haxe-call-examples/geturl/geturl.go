package main

import (
	"fmt"
	"haxegoruntime"
	"runtime"

	"github.com/tardisgo/tardisgo/haxe/hx"
)

func main() {

	url := "http://tardisgo.github.io/LICENSE"
	switch runtime.GOARCH {
	case "js": // js only works in a browser
		url = "http://localhost:8080/geturl.go"
		// put a URL serving this directory here, to avoid x-origin issues
		// then load geturl.html into your browser
		// please note that browser output appears in the javascript console
	}

	// using the cross-platform method (not supported by flash)
	// see the code in package haxegoruntime for how this magic works
	haxegoruntime.BrowserMain(
		func() {
			data, err := haxegoruntime.GetURL(url)
			fmt.Println("Async URL data: ", data, "\nerr: ", err)
		},
		10 /*ms wake-up interval for JS*/)

	// now the simpler method, deprecated for JS and not supported by flash
	fmt.Println("Sync URL fetch:", hx.CallString("!js&&!flash", "haxe.Http.requestUrl", 1, url))
}
