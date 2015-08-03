cd tgo
tardisgo *.go
haxe -main tardis.Go -cp tardis -cp . -cpp tardis/cpp -D static_link -dce full
cd ..
go build -v
./gocallingcpphaxe
