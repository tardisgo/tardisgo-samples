#!/bin/bash
for d in gobyexample/* gohaxelib/*
do
 cd $d
 tardisgo -testall *.go
 cd ..
done

