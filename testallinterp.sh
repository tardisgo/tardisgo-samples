#!/bin/bash
for d in gobyexample/* haxe-call-examples/*
do
 echo "Test running:" $d 
 cd $d
 tardisgo -debug *.go
 haxe -main tardis.Go --interp
 cd ~/go/src/github.com/tardisgo/tardisgo-samples
done

