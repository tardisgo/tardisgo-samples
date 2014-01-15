tardisgo-samples
================

Sample code using TARDIS Go.


For help or general discussions about this repository please go to the [Google Group](https://groups.google.com/d/forum/tardisgo).


To run these examples you will need to install Haxe (from http://haxe.org).

From the directory containing the .go files, first create a "tardis" sub-directory (TODO review this requirement):
```
mkdir tardis
```
Then to translate Go to Haxe, type the command line: 
```
tardisgo filename.go
``` 

Then to run the tardis/Go.hx file generated, type the command line: 
```
haxe -main tardis.Go --interp
```
... or whatever haxe compilation options you want to use. (Note that to compile for PHP you currently need to add the haxe compilation option "--php-prefix tardisgo" to avoid name confilcts).

To run the examples using OpenFL you will need to also install OpenFL (from http://openfl.org). Create the directory and run the tardisgo command as described above from the "Source" directory. Then follow the normal OpenFL/Lime development process.


### gobyexample
---
Examples adapted from https://gobyexample.com/
- hello world
- recursion
- closures
- interfaces
- stateful goroutines
- collection functions (not yet working for PHP, C++ or Java targets)

### OpenFL 
---
- gohandlingmouseevents (adapted from the OpenFL example) - you can see it working live at http://tardisgo.github.io/

### Scripts 
---
Tested on OSX and Ubuntu:
- tgo.sh : transpile all the code in the current directory and run haxe on the result using the user-provided haxe flags
- tgoall.sh : transpile all the code in the current directory for all haxe targets and test each of them (requires all the haxe target languages to be installed, with any required haxlibs)
- tgolime.sh : wrapper for the OpenFL "lime" command, to transpile the Go first

(TODO: windows .BAT examples)

### Tests
---
A directory for tests that pass.

### WIP
---
A directory for non-passing tests that are a work-in-progress.









 
