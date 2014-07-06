package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"os/exec"
	"strings"
	"sync"
)

func main() {
	results := make(chan []byte, 100)
	done := make(chan bool)
	go func() {
		for ln := range results {
			fmt.Println(string(ln))
		}
		done <- true
	}()
	wg := sync.WaitGroup{}
	base, err := os.Getwd()
	if err == nil {
		for _, dir := range []string{"gobyexample", "gohaxelib"} {
			subdir := base + string(os.PathSeparator) + dir
			fds, err := ioutil.ReadDir(subdir)
			if err == nil {
				for _, fd := range fds {
					if fd.IsDir() {
						subsubdir := subdir + string(os.PathSeparator) + fd.Name()
						gfs, err := ioutil.ReadDir(subsubdir)
						if err == nil {
							for _, gf := range gfs {
								if strings.HasSuffix(gf.Name(), ".go") {
									wg.Add(1)
									go func(path, fn string) {
										if os.Chdir(path) == nil {
											out, err := exec.Command("tardisgo", "-debug", "-testall", fn).CombinedOutput()
											if err != nil {
												out = append(out, []byte("\nexec.Command() error for: ")...)
												out = append(out, []byte(path)...)
												out = append(out, []byte(string(os.PathSeparator))...)
												out = append(out, []byte(fn)...)
												out = append(out, []byte("\n-->")...)
												out = append(out, []byte(err.Error())...)
											}
											results <- out
										}
										wg.Done()
									}(subsubdir, gf.Name())
									break
								}
							}
						}
					}
				}
			}
		}
	}
	wg.Wait()
	close(results)
	<-done
}
