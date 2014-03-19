// Basic sends and receives on channels are blocking.
// However, we can use `select` with a `default` clause to
// implement _non-blocking_ sends, receives, and even
// non-blocking multi-way `select`s.

package main

//import "fmt"

func main() {
	messages := make(chan string)
	signals := make(chan bool)

	// Here's a non-blocking receive. If a value is
	// available on `messages` then `select` will take
	// the `<-messages` `case` with that value. If not
	// it will immediately take the `default` case.
	select {
	case msg := <-messages:
		println("received message", msg)
	default:
		println("no message received")
	}

	// A non-blocking send works similarly.
	msg := "hi"
	select {
	case messages <- msg:
		println("sent message", msg)
	default:
		println("no message sent")
	}

	// We can use multiple `case`s above the `default`
	// clause to implement a multi-way non-blocking
	// select. Here we attempt non-blocking receives
	// on both `messages` and `signals`.
	select {
	case msg := <-messages:
		println("received message", msg)
	case sig := <-signals:
		println("received signal", sig)
	default:
		println("no activity")
	}
}
