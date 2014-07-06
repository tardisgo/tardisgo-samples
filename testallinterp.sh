#!/bin/bash
for d in gobyexample/* gohaxelib/*
do
 cd $d
 tardisgo -debug *.go
 haxe -main tardis.Go --interp
 cd ~/go/src/github.com/tardisgo/tardisgo-samples
done

