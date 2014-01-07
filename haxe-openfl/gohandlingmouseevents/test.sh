# only tested on OSX, requires tgo compiler
cd Source/tardis
tgo main.go
if [ "$?" = "0" ]; then
	cd ../..
	lime test $*
fi
