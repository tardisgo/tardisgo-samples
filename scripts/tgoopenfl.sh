# usage as the openfl command
# only tested on OSX, requires tardisgo compiler
cd Source
echo "openfl_$2"
tardisgo -tags "openfl_$2" *.go
if [ "$?" = "0" ]; then
	cd ..
	openfl —build-library=hxcpp $*
fi
