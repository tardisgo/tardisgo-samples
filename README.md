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
- [Non-Blocking Channel Operations](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/nonblock/nonblock.go)
- [range over channel](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/rangeoverchan/rangeoverchan.go)
- [collections](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/collections/collections.go) (uses "strings" package)
- [string functions](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/stringfuncs/stringfuncs.go) (uses "strings" package)
- [stateful goroutines](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/stateful/stateful.go) (uses "sync/atomic" package)
- [sorting by functions](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/sortbyfunc/sortbyfunc.go) (uses "sort" package)
- [encoding to/from base64](https://github.com/tardisgo/tardisgo-samples/blob/master/gobyexample/base64/base64.go) (uses "encoding/base64" package)

### Command line samples showing Haxe called from Go
----
- [geturl](https://github.com/tardisgo/tardisgo-samples/blob/master/haxe-call-examples/geturl/geturl.go) Print tardisgo web site LICENSE in the simplest way possible using the [Haxe pseudo-functions API library](https://github.com/tardisgo/tardisgo/blob/master/haxe/hx/hx.go)
- [printdatetime](https://github.com/tardisgo/tardisgo-samples/blob/master/haxe-call-examples/printdatetime/printdatetime.go) - Print current Haxe date and time using the Haxe "target".Lib.println() API if one exists - shows use of the [_cross API definition](https://github.com/tardisgo/gohaxelib) and also has an example of hand-building a haxe api definition 

### Go as Haxe library examples
----
- [Unicode normalization](https://github.com/tardisgo/tardisgo-samples/blob/master/go-as-haxe-lib-examples/unicode-norm/Main.hx) (pure haxe)
- [Nudity detection](https://github.com/tardisgo/tardisgo-samples/tree/master/go-as-haxe-lib-examples/go-nude) (as a browser html/js application)

### [OpenFL](http://openfl.org) : animated graphical multi-platform samples showing Go called from Haxe
---
You can see these examples working live at http://tardisgo.github.io/
- [gohandlingmouseevents](https://github.com/tardisgo/tardisgo-samples/tree/master/openfl/gohandlingmouseevents/Source) (adapted from the OpenFL example) - Shows use of the [_openfl API definition](https://github.com/tardisgo/gohaxelib) 
- [concurrentgophers](https://github.com/tardisgo/tardisgo-samples/tree/master/openfl/concurrentgophers/Source) (inspired by slide 21 of "[Concurrency is not Parallelism (it's better)](http://concur.rspace.googlecode.com/hg/talk/concur.html#slide-21)" a talk by Rob Pike) - Shows use of the [Haxe pseudo-functions API library](https://github.com/tardisgo/tardisgo/blob/master/tardisgolib/hx/hx.go)
- [8concurrentgophers](https://github.com/tardisgo/tardisgo-samples/tree/master/openfl/8concurrentgophers/Source) (as above, but with 8 gophers rather than 2, for FOSDEM14 presentation; shows maximum use of Haxe, accessing Go variables as required - not currently recommended, as it requires a knowledge of TARDISgo internal datastructures) 

To compile and run them you will also need to follow the instructions to install OpenFL [here](http://www.openfl.org/download/). From the "Source" directory, check there is a "tardis" sub-directory and run the tardisgo command as normal e.g. "tardisgo gophers.go". Then follow the normal OpenFL development process from the directory above, try: "openfl test html5". Or use the tgoopenfl.sh script described below. Tested with OpenFL command-line tools version 2.1.6.

### Scripts 
---
For OSX and Ubuntu users, here are some scripts that might help, they are written for HAXE 3.1.1. NOTE: The tardisgo -testall flag (e.g. "tardisgo -testall mycode.go") provides the same functionality as tgoall.sh/tgoallu.sh below, but runs all the jobs concurrently and so is faster:
- [tgo.sh](https://github.com/tardisgo/tardisgo-samples/blob/master/scripts/tgo.sh) : transpile all the code in the current directory and run haxe on the result using the user-provided haxe flags
- [tgoall.sh](https://github.com/tardisgo/tardisgo-samples/blob/master/scripts/tgoall.sh) : transpile all the code in the current directory for all haxe targets and test each of them (requires all the haxe target languages to be installed, with any required haxelibs, tested on OSX)
- [tgoallu.sh](https://github.com/tardisgo/tardisgo-samples/blob/master/scripts/tgoallu.sh) :  Ubuntu version of tgoall.sh
- [tgoopenfl.sh](https://github.com/tardisgo/tardisgo-samples/blob/master/scripts/tgolime.sh) : wrapper for the OpenFL command, to transpile the Go first

### Benchmarks
---
- mandlebrot 
- fannkuch
- binarytree

A snapshot of TARDIS Go's poor relative performance as at January 2014 can be found in the graph [here](https://speakerdeck.com/elliott5/write-your-own-go-compiler?slide=29). But please note that both llgo and GopherJS had elements of their core Go implementations missing when these tests were run. 

Improving the speed of TARDIS Go will be a focus of future development, with results reported at intervals.


### WIP
---
A directory for non-passing tests that are a work-in-progress and are referenced by tardisgo issues.

