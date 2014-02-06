// Adapted from https://gobyexample.com/stateful-goroutines

// In the previous example we used explicit locking with
// mutexes to synchronize access to shared state across
// multiple goroutines. Another option is to use the
// built-in synchronization features of  goroutines and
// channels to achieve the same result. This channel-based
// approach aligns with Go's ideas of sharing memory by
// communicating and having each piece of data owned
// by exactly 1 goroutine.

package main

import (
	// Not available in TARDIS Go as at Jan'14
	// "fmt"
	// "time"
	// "math/rand"

	_ "github.com/tardisgo/tardisgo/golibruntime/sync/atomic" // runtime functions for sync/atomic
	"sync/atomic"

	"github.com/tardisgo/tardisgo/tardisgolib" // runtime functions for TARDIS Go
)

// In this example our state will be owned by a single
// goroutine. This will guarantee that the data is never
// corrupted with concurrent access. In order to read or
// write that state, other goroutines will send messages
// to the owning goroutine and receive corresponding
// replies. These `readOp` and `writeOp` `struct`s
// encapsulate those requests and a way for the owning
// goroutine to respond.
type readOp struct {
	key  int
	resp chan int
}
type writeOp struct {
	key  int
	val  int
	resp chan bool
}

func main() {

	// As before we'll count how many operations we perform.
	var ops int64 = 0

	// The `reads` and `writes` channels will be used by
	// other goroutines to issue read and write requests,
	// respectively.
	reads := make(chan *readOp)
	writes := make(chan *writeOp)

	// Here is the goroutine that owns the `state`, which
	// is a map as in the previous example but now private
	// to the stateful goroutine. This goroutine repeatedly
	// selects on the `reads` and `writes` channels,
	// responding to requests as they arrive. A response
	// is executed by first performing the requested
	// operation and then sending a value on the response
	// channel `resp` to indicate success (and the desired
	// value in the case of `reads`).
	go func() {
		state := make(map[int]int)
		for {
			select {
			case read := <-reads:
				read.resp <- state[read.key]
			case write := <-writes:
				state[write.key] = write.val
				write.resp <- true
			}
		}
	}()

	// This starts 100 goroutines to issue reads to the
	// state-owning goroutine via the `reads` channel.
	// Each read requires constructing a `readOp`, sending
	// it over the `reads` channel, and the receiving the
	// result over the provided `resp` channel.
	for r := 0; r < 100; r++ {
		go func() {
			for {
				read := &readOp{
					key:  int(tardisgolib.HAXE("Std.random(5);")), // rand.Intn(5),
					resp: make(chan int)}
				reads <- read
				<-read.resp
				atomic.AddInt64(&ops, 1)
			}
		}()
	}

	// We start 10 writes as well, using a similar
	// approach.
	for w := 0; w < 10; w++ {
		go func() {
			for {
				write := &writeOp{
					key:  int(tardisgolib.HAXE("Std.random(5);")),   // rand.Intn(5),
					val:  int(tardisgolib.HAXE("Std.random(100);")), // rand.Intn(100),
					resp: make(chan bool)}
				writes <- write
				<-write.resp
				atomic.AddInt64(&ops, 1)
			}
		}()
	}

	// Let the goroutines work for a second.
	//time.Sleep(time.Second)
	for i := 0; i < 1000; i++ {
		tardisgolib.Gosched()
	}

	// Finally, capture and report the `ops` count.
	opsFinal := atomic.LoadInt64(&ops)
	//fmt.Println("ops:", opsFinal)
	println("ops:", int(opsFinal)) // TODO println of a 64-bit int does not show the actual value on all platforms, only the type name see issue #18
}
