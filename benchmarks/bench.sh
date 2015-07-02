# run the benchmarks
#go get -u github.com/gopherjs/gopherjs
cd mandel
echo "mandel benchmark:"
go build mandel.go
echo "go:"
time ./mandel
echo "TARDISgo default settings"
tardisgo -haxe all mandel.go
java -jar ~/closure/compiler.jar  --js tardis/go.js >tardis/go-opt.js 2>/dev/null
echo "JS after closure"
time node<tardis/go-opt.js
#echo "TARDISgo benchmark settings"
#tardisgo -haxe bench mandel.go
#java -jar ~/closure/compiler.jar  --js tardis/go-bench.js >tardis/go-bench-opt.js 2>/dev/null
#echo "benchmark settings JS after closure"
#time node<tardis/go-bench-opt.js
echo "GopherJS"
gopherjs build mandel.go
time node<mandel.js
cd ../fannkuch
echo "fannkuch benchmark:"
go build fannkuch.go
echo "fannkuch go:"
time ./fannkuch
echo "fannkuch TARDISgo default settings"
tardisgo -haxe all fannkuch.go
java -jar ~/closure/compiler.jar  --js tardis/go.js >tardis/go-opt.js 2>/dev/null
echo "fannkuch JS after closure"
time node<tardis/go-opt.js
#echo "fannkuch TARDISgo benchmark settings"
#tardisgo -haxe bench fannkuch.go
#java -jar ~/closure/compiler.jar  --js tardis/go-bench.js >tardis/go-bench-opt.js 2>/dev/null
#echo "fannkuch benchmark settings JS after closure"
#time node<tardis/go-bench-opt.js
echo "fannkuch GopherJS"
gopherjs build fannkuch.go
time node<fannkuch.js
cd ../binarytree
echo "binarytree benchmark:"
go build binarytree.go
echo "binarytree go:"
time ./binarytree
echo "binarytree TARDISgo default settings"
tardisgo -haxe all binarytree.go
java -jar ~/closure/compiler.jar  --js tardis/go.js >tardis/go-opt.js 2>/dev/null
echo "binarytree JS after closure"
time node<tardis/go-opt.js
#echo "binarytree TARDISgo benchmark settings"
#tardisgo -haxe bench binarytree.go
#java -jar ~/closure/compiler.jar  --js tardis/go-bench.js >tardis/go-bench-opt.js 2>/dev/null
#echo "binarytree benchmark settings JS after closure"
#time node<tardis/go-bench-opt.js
echo "binarytree GopherJS"
gopherjs build binarytree.go
time node<binarytree.js
