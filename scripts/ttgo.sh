# TEST MODE  -  NOTE this is WIP...

tardisgo -test -debug $*
if [ "$?" = "0" ]; then
	haxe -main tardis.Go -dce full -js tardis/ttgo.js
	node < tardis/ttgo.js
fi
