// animation inspired by http://concur.rspace.googlecode.com/hg/talk/concur.html#landing-slide
// gopher logo by Renée French

package main

import "github.com/tardisgo/tardisgo/tardisgolib"

func main() {}

var bigpile, smallpile, oven chan int
var Sprite1X, Sprite1Y, Sprite2X, Sprite2Y float64
var Sprite1state, Sprite2state int

const (
	Pick = iota
	Full
	Shovel
	Empty
)

// This function is called to set-off the gophers
func StartGophers() {
	bigpile = make(chan int)
	bigpile <- 1 // start low, so that left-hand gopher moves fast
	go fillbigpile()
	smallpile = make(chan int)
	smallpile <- 10 // start high, so that right-hand gopher moves slow
	go gopher(&Sprite1X, &Sprite1Y, &Sprite1state, bigpile, smallpile)
	oven = make(chan int)
	go gopher(&Sprite2X, &Sprite2Y, &Sprite2state, smallpile, oven)
	go fire()
}

func fillbigpile() {
	for {
		select { // randomized select
		case bigpile <- 1:
		case bigpile <- 2:
		case bigpile <- 3:
		case bigpile <- 8:
		case bigpile <- 9:
		case bigpile <- 10:
		}
	}
}

func fire() {
	for {
		<-oven
	}
}

func gopher(x, y *float64, state *int, in, out chan int) {
	for {
		cartLoad := pickBooks(x, y, state, in)
		pushBooks(x, y, state, cartLoad)
		fireBooks(x, y, state, cartLoad, out)
		moreBooks(x, y, state)
	}
}

func pickBooks(x, y *float64, state *int, in chan int) int {
	*state = Pick
	*x = 0
	v := <-in
	loop(v) // spend longer picking some loads and putting them on the cart
	return v
}
func pushBooks(x, y *float64, state *int, cartLoad int) {
	*state = Full
	for *x = 0.0; *x < 150.0; (*x) += 10.0 / float64(cartLoad) {
		if *y > 0.0 { // create bumps in the road
			*y = 0.0
		} else {
			*y = float64(tardisgolib.HAXE("Std.random(3);"))
		}
		tardisgolib.Gosched() // without this the goroutine would not show state
	}
	if *x > 150.0 { // constrain large x offsets
		*x = 150.0
	}
	*y = 0.0
}
func fireBooks(x, y *float64, state *int, cartLoad int, out chan int) {
	*state = Shovel
	loop(cartLoad) // spend longer unloading some loads into the fire
	out <- cartLoad
}
func moreBooks(x, y *float64, state *int) {
	*state = Empty
	for *x > 0.0 {
		*x -= 10.0
		if *x < 0.0 { // no -ve x offsets please
			*x = 0.0
		}
		if *y > 0.0 { // create bumps in the road
			*y = 0.0
		} else {
			*y = float64(tardisgolib.HAXE("Std.random(5);"))
		}
		tardisgolib.Gosched() // without this the goroutine would not show state
	}
	*y = 0.0
}
func loop(n int) { // add some delay when required
	for n > 0 {
		n--
		tardisgolib.Gosched()
	}
}
