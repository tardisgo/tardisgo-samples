# example only, your path to the closure compiler may be different
java -jar ~/closure/compiler.jar --compilation_level ADVANCED_OPTIMIZATIONS --js tardis/go.js >tardis/go-ao.js
java -jar ~/closure/compiler.jar --compilation_level ADVANCED_OPTIMIZATIONS --js tardis/go-dv.js >tardis/go-dv-ao.js
java -jar ~/closure/compiler.jar --compilation_level ADVANCED_OPTIMIZATIONS --js tardis/go-sf.js >tardis/go-sf-ao.js
node<tardis/go-ao.js
node<tardis/go-dv-ao.js
node<tardis/go-sf-ao.js
ls -l tardis/*.js
