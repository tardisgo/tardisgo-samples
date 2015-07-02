package main

/*
#include <stdio.h>
#include <stdlib.h>
extern int hxmain(int argc, char *argv[]);
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
	C.hxmain(0, nil)
}
