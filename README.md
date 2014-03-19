# TARDIS Go sample code

Sample code using [TARDIS Go](https://github.com/tardisgo/tardisgo), both command line and animated graphical.

For help or general discussions about this repository please go to the [Google Group](https://groups.google.com/d/forum/tardisgo).


### [Go by example](https://gobyexample.com/) : adapted command line examples

---
- [hello world](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/helloworld/helloworld.go)
- [variadic functions](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/variadic/variadic.go)
- [recursion](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/recursion/recursion.go)
- [closures](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/closures/closures.go)
- [methods](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/methods/methods.go)
- [interfaces](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/interfaces/interfaces.go)
- [channel synchronization](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/chansync/chansync.go)
- [range over channel](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/rangeoverchan/rangeoverchan.go)
- [stateful goroutines](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/stateful/stateful.go) (uses "sync/atomic" package)
- [sorting by functions](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/sortbyfunc/sortbyfunc.go) (uses "sort" package)
- [collection functions](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/collections/collections.go) (uses "strings" package)
- [string functions](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/stringfuncs/stringfuncs.go) (uses "strings" package; strings.split function not yet working correctly for Flash target)
- [number parsing](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/numberparsing/numberparsing.go) (uses "strconv" package, not working for Flash target)
- [base64 encoding](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/base64/base64.go) (uses "encoding/base64" package, not working for PHP target)


### [gohaxelib](https://github.com/tardisgo/gohaxelib) : command line samples showing Haxe called from Go
---
The gohaxelib methodology is still very experimental and incomplete, as are these examples. To run the [gohaxlib](https://github.com/tardisgo/gohaxelib) examples, you will first need to:
```
go get "github.com/tardisgo/gohaxelib/_haxeapi"
```
- [printdatetime](https://github.com/tardisgo/tardisgo-samples/blob/master/gohaxelib/printdatetime/printdatetime.go) - Print current Haxe date and time using the Haxe "target".Lib.println() API if one exists 
- [geturl](https://github.com/tardisgo/tardisgo-samples/blob/master/gohaxelib/geturl/geturl.go) Print tardisgo web site LICENSE in the simplest way possible (this particular formulation does not work for JavaScript, C# or Flash)



### [OpenFL](http://openfl.org) : animated graphical multi-platform samples showing Go called from Haxe
---
You can see these examples working live at http://tardisgo.github.io/
- [gohandlingmouseevents](https://github.com/tardisgo/tardisgo-samples/tree/master/openfl/gohandlingmouseevents/Source) (adapted from the OpenFL example) 
- [concurrentgophers](https://github.com/tardisgo/tardisgo-samples/tree/master/openfl/concurrentgophers/Source) (inspired by slide 21 of "[Concurrency is not Parallelism (it's better)](http://concur.rspace.googlecode.com/hg/talk/concur.html#slide-21)" a talk by Rob Pike)
- [8concurrentgophers](https://github.com/tardisgo/tardisgo-samples/tree/master/openfl/8concurrentgophers/Source) (as above, but with 8 gophers rather than 2, for FOSDEM14 presentation; modified 19-Mar-2014 to use new openfl-html5 back-end)

To compile and run them you will also need to follow the instructions to install OpenFL [here](http://www.openfl.org/download/). From the "Source" directory, check there is a "tardis" sub-directory and run the tardisgo command as normal e.g. "tardisgo mouse.go". Then follow the normal OpenFL/Lime development process from the directory above, try: "lime test html5". Or use the tgolime.sh script described below. 
 


### Scripts 
---
For OSX and Ubuntu users, here are some scripts that might help, they are written for HAXE 3.1.1. NOTE: The tardisgo -testall flag (e.g. "tardisgo -testall mycode.go") provides the same functionality as tgoall.sh/tgoallu.sh below, but runs all the jobs concurrently and so is faster:
- [tgo.sh](https://github.com/tardisgo/tardisgo-samples/blob/master/scripts/tgo.sh) : transpile all the code in the current directory and run haxe on the result using the user-provided haxe flags
- [tgoall.sh](https://github.com/tardisgo/tardisgo-samples/blob/master/scripts/tgoall.sh) : transpile all the code in the current directory for all haxe targets and test each of them (requires all the haxe target languages to be installed, with any required haxelibs, tested on OSX)
- [tgoallu.sh](https://github.com/tardisgo/tardisgo-samples/blob/master/scripts/tgoallu.sh) :  Ubuntu version of tgoall.sh
- [tgolime.sh](https://github.com/tardisgo/tardisgo-samples/blob/master/scripts/tgolime.sh) : wrapper for the OpenFL "lime" command, to transpile the Go first




### Benchmarks
---
- mandlebrot
- fannkuch

A snapshot of TARDIS Go's poor relative performance as at January 2014 can be found in the graph [here](https://speakerdeck.com/elliott5/write-your-own-go-compiler?slide=29). But please note that both llgo and GopherJS had elements of their core Go implementations missing when these tests were run. 

Improving the speed of TARDIS Go will be a focus of future development, with results reported at intervals.


### WIP
---
A directory for non-passing tests that are a work-in-progress and are referenced by tardisgo issues.

