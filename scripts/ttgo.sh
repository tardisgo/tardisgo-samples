# TEST MODE  -  NOTE this is WIP...

tardisgo -debug=true *.go
if [ "$?" = "0" ]; then
	haxe -main tardis.Go -cp tardis -dce full -Dgodebug $*
fi
