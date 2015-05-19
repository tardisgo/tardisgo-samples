# run the benchmarks
#go get -u github.com/gopherjs/gopherjs
cd mandel
echo "mandel benchmark:"
go build mandel.go
echo "go:"
time ./mandel
tardisgo -haxe all mandel.go
echo "GopherJS"
gopherjs build mandel.go
time node<mandel.js
cd ../fannkuch
echo "fannkuch benchmark:"
go build fannkuch.go
echo "go:"
time ./fannkuch
tardisgo -haxe all fannkuch.go
echo "GopherJS"
gopherjs build fannkuch.go
time node<fannkuch.js
cd ../binarytree
echo "binarytree benchmark:"
go build binarytree.go
echo "go:"
time ./binarytree
tardisgo -haxe all binarytree.go
echo "GopherJS"
gopherjs build binarytree.go
time node<binarytree.js
