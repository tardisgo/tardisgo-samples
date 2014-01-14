# Compile all the go in this directory with TARDIS Go for with a given set of haxe flags
# only tested on OSX 
# usage: 
#	tgohaxe.sh <haxe compile options>
# examples:
# 	tgo.sh --interp
# 	tgo.sh -neko tardisgo.n
# 	tgo.sh -js tardisgo.js
# 	tgo.sh -cpp cpp
# 	tgo.sh -java java
# 	tgo.sh -cs cs
# 	tgo.sh -php php --php-prefix tardisgo

tardisgo *.go
if [ "$?" = "0" ]; then
	haxe -main tardis.Go -dce full $*
fi
