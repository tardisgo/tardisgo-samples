# usage as the lime command
# only tested on OSX, requires tardisgo compiler
cd Source
tardisgo *.go
if [ "$?" = "0" ]; then
	cd ..
	lime —build-library=hxcpp $*
fi
