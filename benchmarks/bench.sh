# run the benchmarks
#go get -u github.com/gopherjs/gopherjs
cd mandel
echo "mandel benchmark:"
go build mandel.go
echo "go:"
time ./mandel
echo "TARDISgo default settings"
tardisgo -haxe all mandel.go
#echo "TARDISgo benchmark settings"
#tardisgo -haxe bench mandel.go
echo "GopherJS"
gopherjs build mandel.go
time node<mandel.js
cd ../fannkuch
echo "fannkuch benchmark:"
go build fannkuch.go
echo "go:"
time ./fannkuch
echo "TARDISgo default settings"
tardisgo -haxe all fannkuch.go
#echo "TARDISgo benchmark settings"
#tardisgo -haxe bench fannkuch.go
echo "GopherJS"
gopherjs build fannkuch.go
time node<fannkuch.js
cd ../binarytree
echo "binarytree benchmark:"
go build binarytree.go
echo "go:"
time ./binarytree
echo "TARDISgo default settings"
tardisgo -haxe all binarytree.go
#echo "TARDISgo benchmark settings"
#tardisgo -haxe bench binarytree.go
echo "GopherJS"
gopherjs build binarytree.go
time node<binarytree.js
