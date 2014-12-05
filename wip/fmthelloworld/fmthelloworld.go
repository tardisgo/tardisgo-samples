// the classic hello world, using fmt - currenly a long way from working!
package main

import (
	"bufio"
	"os"
	//"fmt"
)

func main() {

	w := bufio.NewWriter(os.Stdout)
	w.Write([]byte("Hello, "))
	w.Write([]byte("world!"))
	w.Write([]byte("\n"))
	w.Flush() // Don't forget to flush!

	//fmt.Printf("Hello world - %d!\n", 42)
}
