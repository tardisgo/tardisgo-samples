# example only, your path to the closure compiler may be different
java -jar ~/closure/compiler.jar --compilation_level ADVANCED_OPTIMIZATIONS --js tardis/go.js >tardis/go-ao.js
java -jar ~/closure/compiler.jar --compilation_level ADVANCED_OPTIMIZATIONS --js tardis/go-fu.js >tardis/go-fu-ao.js
node<tardis/go-ao.js
node<tardis/go-fu-ao.js
ls -l tardis/*.js
