package main

/*
#cgo LDFLAGS: -stdlib=libstdc++ tgo/tardis/cpp/libGo.a /usr/lib/haxe/lib/hxcpp/3,2,102/lib/Mac64/libstd.a /usr/lib/haxe/lib/hxcpp/3,2,102/lib/Mac64/libzlib.a /usr/lib/haxe/lib/hxcpp/3,2,102/lib/Mac64/libregexp.a
// /usr/lib/haxe/lib/hxcpp/3,2,102/lib/Mac64/libsqlite.a /usr/lib/haxe/lib/hxcpp/3,2,102/lib/Mac64/libmysql5.a
#include <stdio.h>
#include <stdlib.h>
extern int hxmain(int argc, char *argv[]);

extern int Myadd(int a, int b);

int myhxmain(){
	fprintf(stderr,"myhxmain()!\n");
	Myadd(1,2);
	return hxmain(0,0);
}

int gogo;

extern void tardisgo_timereventhandler(int run_limit);

extern int Gohaxecpp_Int2Dynamic(int i);
extern int Gohaxecpp_Dynamic2Int(int i);

*/
import "C"
import "unsafe"

func Print(s string) {
	cs := C.CString(s)
	defer C.free(unsafe.Pointer(cs))
	C.fputs(cs, (*C.FILE)(C.stdout))
}

func main() {
	Print("Hello world from C\n")
	C.gogo = 1219
	println("myhxmain=", C.myhxmain())
	println("Life after TARDISgo=", C.gogo)
	for i := 0; i < 10; i++ {
		C.tardisgo_timereventhandler(C.int(i))
	}
	ss := C.Gohaxecpp_Int2Dynamic(77)
	println("SevenSeven=", ss, C.Gohaxecpp_Dynamic2Int(ss))
}
