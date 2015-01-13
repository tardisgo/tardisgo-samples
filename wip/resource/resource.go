package main

import (
	"syscall"

	"github.com/tardisgo/tardisgo/haxe/hx"
)

import "io/ioutil"

func main() {
	list := []string{}
	names := hx.GetDynamic("", "haxe.Resource.listNames()")
	println(names)
	l := 0
	if !hx.IsNull(names) {
		l = hx.FgetInt("", names, "", "length")
	}
	println(l)
	for n := 0; n < l; n++ {
		nam := hx.MethString("", names, "", "shift", 0)
		list = append(list, nam)
		/*
			println("FileName:" + nam)
			if path.Ext(nam) != ".zip" {
				b := hx.Resource(nam)
				println(string(b))
				err := os.MkdirAll(path.Dir(nam), 0777)
				if err != nil {
					println("MkdirAll ERROR! " + err.Error())
				} else {
					err := ioutil.WriteFile(nam, b, 0777)
					if err != nil {
						println("ERROR! " + err.Error())
					}
				}
			}
		*/
	}
	for _, fn := range list {
		buf, err := ioutil.ReadFile(fn)
		if err != nil {
			println(fn + " read-back ERROR! " + err.Error())
		} else {
			println(fn + " -> " + string(buf))
		}
	}
	log, err := ioutil.ReadFile("/fsinit.log")
	if err != nil {
		println("/fsinit.log read-back problem: " + err.Error())
	} else {
		println("/fsinit.log -> " + string(log))
	}
	syscall.UnzipFS("tgofs.zip")
	fi, err := ioutil.ReadDir("/test")
	if err != nil {
		println("/test ReadDir read-back problem: " + err.Error())
	} else {
		for _, f := range fi {
			fn := "/test/" + f.Name()
			buf, err := ioutil.ReadFile(fn)
			if err != nil {
				println(fn + " read-back ERROR! " + err.Error())
			} else {
				println(fn + " -> " + string(buf))
			}
		}
	}
}
