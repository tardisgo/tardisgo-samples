# usage as the openfl command
# only tested on OSX, requires tardisgo compiler
cd Source
tardisgo *.go
if [ "$?" = "0" ]; then
	cd ..
	openfl —build-library=hxcpp $*
fi
