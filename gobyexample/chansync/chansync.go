package main

import "fmt"

func worker(done chan bool) {
	fmt.Println("Work at something...")
	done <- true
}

func main() {
	done := make(chan bool, 1)
	go worker(done)
	<-done
	fmt.Println("Done!")
}
