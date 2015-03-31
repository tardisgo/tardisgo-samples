# example only, your path to the closure compiler may be different
#java -jar ~/closure/compiler.jar --compilation_level ADVANCED_OPTIMIZATIONS --js tardis/go.js >tardis/go-ao.js
#java -jar ~/closure/compiler.jar --compilation_level ADVANCED_OPTIMIZATIONS --js tardis/go-fu.js >tardis/go-fu-ao.js
java -jar ~/closure/compiler.jar --js tardis/go.js >tardis/go-opt.js
java -jar ~/closure/compiler.jar --js tardis/go-fu.js >tardis/go-fu-opt.js
node<tardis/go-opt.js
node<tardis/go-fu-opt.js
ls -l tardis/*.js
