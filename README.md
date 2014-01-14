tardisgo-samples
================

Sample code using TARDIS Go.

To run these examples you will need to install Haxe (from http://haxe.org).

From the directory containing the .go files, to translate Go to Haxe, type the command line: 
```
tardisgo filename.go
```
Note that a "tardis" sub-directory must exist before the command is run (which it does in these samples). 

Then to run the tardis/Go.hx file generated, type the command line: 
```
haxe -main tardis.Go --interp
```
... or whatever haxe compilation options you want to use. (Note that to compile for PHP you currently need to add the haxe compilation option "--php-prefix tardisgo" to avoid name confilcts).

To run the examples using OpenFL you will need to also install OpenFL (from http://openfl.org). Run the tardisgo command as described above from the "Source" directory. Then follow the normal OpenFL/Lime development process.


gobyexample examples
--------------------

Examples adapted from https://gobyexample.com/
- hello world
- recursion
- closures
- interfaces
- stateful goroutines
- collection functions (not yet working for PHP, C++ or Java targets)



OpenFL examples
---------------
- gohandlingmouseevents (adapted from the OpenFL example) - you can see it working live at http://tardisgo.github.io/


Tests
-----
A directory for tests that pass.

WIP
---
A directory for non-passing tests that are a work-in-progress.









 
