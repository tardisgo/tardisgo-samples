haxe -main HelloWorld --interp
haxe -main HelloWorld --macro "ExampleJSGenerator.use()" -js hw.js
./postproc/postproc
go run hw.go