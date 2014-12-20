# Compile all the go in this directory with TARDIS Go for with a given set of haxe flags
# only tested on OSX 
# usage: 
#	tgohaxe.sh <haxe compile options>
# examples:
# 	tgo.sh --interp
# 	tgo.sh -neko tardis/tardisgo.n
# 	tgo.sh -js tardis/tardisgo.js
# 	tgo.sh -cpp tardis/cpp
# 	tgo.sh -java tardis/java
# 	tgo.sh -cs tardis/cs
# 	tgo.sh -php tardis/php --php-prefix tardisgo

tardisgo *.go
if [ "$?" = "0" ]; then
	haxe -main tardis.Go -dce full $*
fi
