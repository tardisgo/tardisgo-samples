# TARDIS Go sample code

Sample code using [TARDIS Go](https://github.com/tardisgo/tardisgo).

For help or general discussions about this repository please go to the [Google Group](https://groups.google.com/d/forum/tardisgo).


### Go by example - samples adapted from https://gobyexample.com/

---
- hello world
- variadic functions
- recursion
- closures
- interfaces
- channel synchronization
- stateful goroutines (uses "sync/atomic" package)
- sorting by functions (uses "sort" package)
- collection functions (uses "strings" package; not yet working for PHP, C++ or Java targets)
- base64 encoding (uses "encoding/base64" package; not yet working for PHP target)


### gohaxelib - samples showing Haxe called from Go
---
To run the gohaxlib examples, you will first need to:
```
go get "github.com/tardisgo/gohaxelib/_haxeapi"
```
- printdatetime - Print current Haxe date and time using the Haxe "target".Lib.println() API if one exists 


### OpenFL - samples showing Go called from Haxe
---
To run the OpenFl examples you will need to also install [OpenFL](http://openfl.org). Create the directory and run the tardisgo command as normal from the "Source" directory. Then follow the normal OpenFL/Lime development process. Or use the tgolime.sh script described below. 
- gohandlingmouseevents (adapted from the OpenFL example) - you can see it working live at http://tardisgo.github.io/
 


### Scripts 
---
For OSX and Ubuntu users, here are some scripts that might help:
- tgo.sh : transpile all the code in the current directory and run haxe on the result using the user-provided haxe flags
- tgoall.sh : transpile all the code in the current directory for all haxe targets and test each of them (requires all the haxe target languages to be installed, with any required haxelibs, not tested on Ubuntu)
- tgolime.sh : wrapper for the OpenFL "lime" command, to transpile the Go first

(TODO: windows .BAT examples)


### Benchmarks
---
- mandlebrot
- fannkuch

(Results will be published at a talk on 2nd February 2014)


### WIP
---
A directory for non-passing tests that are a work-in-progress and are referenced by tardisgo issues.

