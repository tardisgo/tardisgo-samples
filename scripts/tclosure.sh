# example only, your path to the closure compiler may be different
java -jar ~/closure/compiler.jar --js tardis/go.js >tardis/go-opt.js  2>/dev/null
#java -jar ~/closure/compiler.jar --compilation_level ADVANCED_OPTIMIZATIONS --js tardis/go.js >tardis/go-ao.js  2>/dev/null
ls -l tardis/*.js
time node<tardis/go-opt.js
#time node<tardis/go-ao.js
