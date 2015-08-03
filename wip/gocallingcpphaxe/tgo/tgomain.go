package main

import (
	"fmt"
	"strings"
)
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
	println("TARDISgo MOL=", MOL(0), hx.CallInt("", "TgoMOL.run", 1, 1))
	println("TARDISgo GoHxRPC1=", GoHxRPC("1st call..."))
	cs := hx.CallDynamic("", "cpp.NativeString.c_str", 1, "...2nd Call!")
	c2 := hx.CallDynamic("", "GoHxRPC.run", 1, cs)
	c2s := hx.CallString("cpp", "cpp.NativeString.fromPointer", 1, c2)
	println("TARDISgo GoHxRPC2=", c2s)
	go doStuff()
}

func doStuff() {
	for true {
		fmt.Println("doStuff")
		runtime.Gosched()
	}
}

func MOL(l int) int {
	hx.Source("TgoMOL", `
package tardis;

@:cppFileCode('extern "C" int tgoMOL(int l){return tardis::TgoMOL_obj::run(l);};')

class TgoMOL {
	public static function run(l:Int):Int{
		return tardis.Go_main_MMOOLL.hx(l);
	}
}
		`)
	return 42 * l
}

func GoHxRPC(params string) string {
	hx.Source("GoHxRPC", `
package tardis;

@:cppFileCode('extern "C" char *GoHxRPC(char *p){return tardis::GoHxRPC_obj::run(p);};')

class GoHxRPC {
	public static function run(l:cpp.ConstPointer<cpp.Char>):cpp.ConstPointer<cpp.Char>{
		try {
			var str = cpp.NativeString.fromPointer(l);
			var rstr = tardis.Go_main_GGoHHxRRPPCC.hx(str);
			return cpp.NativeString.c_str(rstr);
		} catch( unknown : Dynamic ) {
			var errMsg = Std.string(unknown);
   			trace("GoHxRPC exception : "+errMsg);
   			return null;
		}
	}
}
		`)
	return strings.ToUpper(params)
}
