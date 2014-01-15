package main

func worker(done chan bool) {
	println("Work at something...")
	done <- true
}

func main() {
	done := make(chan bool, 1)
	go worker(done)
	<- done
	println("Done!")
}

