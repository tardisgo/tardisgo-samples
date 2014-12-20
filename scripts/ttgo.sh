# TEST MODE  -  NOTE this is WIP...

tardisgo -debug=true *.go
if [ "$?" = "0" ]; then
	haxe -main tardis.Go -dce full -Dgodebug $*
fi
