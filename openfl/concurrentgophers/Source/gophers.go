// animation inspired by http://blog.golang.org/concurrency-is-not-parallelism
// gopher logo by Renée French

package main

import (
	"github.com/tardisgo/tardisgo/tardisgolib"
	"github.com/tardisgo/tardisgo/tardisgolib/hx"
)

// see haxe file Main.hx for the true entry point
func main() {}

// the globals below are inspected by the Haxe interface code below to move and change sprites to create the animation
var bigpile, smallpile, oven chan int
var Sprite1X, Sprite1Y, Sprite2X, Sprite2Y float64
var Sprite1state, Sprite2state int

const ( // constants for the state of a gopher, also used by Haxe code
	Pick = iota
	Full
	Shovel
	Empty
)

// This function is called to set-off the gophers
func startGophers() {
	bigpile = make(chan int)
	bigpile <- 1     // start low, so that left-hand gopher moves fast
	go fillbigpile() // keep adding randomly to the big pile

	smallpile = make(chan int)
	smallpile <- 10 // start high, so that right-hand gopher moves slow

	oven = make(chan int)
	go fire() // burn everything that arrives!

	// now start off the two gophers
	go gopher(&Sprite1X, &Sprite1Y, &Sprite1state, bigpile, smallpile)
	go gopher(&Sprite2X, &Sprite2Y, &Sprite2state, smallpile, oven)
}

func fillbigpile() {
	for {
		select { // randomized select to create large or small loads
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

// an individual gopher, animated with logos by the Haxe code
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
			*y = float64(hx.CallInt("", "Std.random", 1, 3)) // random small bumps
		}
		tardisgolib.Gosched() // without this, the animation would not show each state
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
			*y = float64(hx.CallInt("", "Std.random", 1, 5)) // random bigger bumps
		}
		tardisgolib.Gosched() // would not show state without this, the animation would jump.
	}
	*y = 0.0
}
func loop(n int) { // add some delay when required
	for n > 0 {
		n--
		tardisgolib.Gosched() // give up control in order to show the gopher waiting
	}
}

/*************************************** Haxe/OpenFL interface code *************************************/

var mainThis, headline, Books, Logo1, Logo2, Sprite1, Sprite2, goTimer uintptr

const (
	s1x = 90
	s1y = 45
	s2x = 420
	s2y = 45
)

func makeText(selectable bool, x, y, width, height, textColor int, text string) uintptr {
	txt := hx.New("", "openfl.text.TextField", 0)
	hx.FsetBool("", txt, "openfl.text.TextField", "selectable", selectable)
	hx.FsetInt("", txt, "openfl.text.TextField", "x", x)
	hx.FsetInt("", txt, "openfl.text.TextField", "y", y)
	hx.FsetInt("", txt, "openfl.text.TextField", "width", width)
	hx.FsetInt("", txt, "openfl.text.TextField", "height", height)
	hx.FsetInt("", txt, "openfl.text.TextField", "textColor", textColor)
	hx.FsetString("", txt, "openfl.text.TextField", "text", text)
	hx.Meth("", mainThis, "", "addChild", 1, txt)
	return txt
}

func makeBitmap(file string) uintptr {
	bmd := hx.CallDynamic("", "openfl.Assets.getBitmapData", 1, file)
	return hx.New("", "openfl.display.Bitmap", 1, bmd)
}

func makeSprite(bitmap uintptr, x, y int) uintptr {
	sp := hx.New("", "openfl.display.Sprite", 0)
	hx.Meth("", sp, "", "addChild", 1, bitmap)
	hx.FsetInt("", sp, "openfl.display.Sprite", "x", x)
	hx.FsetInt("", sp, "openfl.display.Sprite", "y", y)
	hx.Meth("", mainThis, "", "addChild", 1, sp)
	return sp
}

var emptyPilePng, smallPilePng, pickPng1, pickPng2, fullPng1, fullPng2, emptyPng1, emptyPng2, shovelPng1, shovelPng2 uintptr

func Start(mt uintptr) {
	mainThis = mt // this is actually a Haxe object, therefore a pointer, so can't be passed by value within Go

	// setup the animated PNG bitmaps
	emptyPilePng = makeBitmap("assets/emptypile.png")
	smallPilePng = makeBitmap("assets/smallpile.png")
	pickPng1 = makeBitmap("assets/pick.png")
	pickPng2 = makeBitmap("assets/pick.png")
	fullPng1 = makeBitmap("assets/full.png")
	fullPng2 = makeBitmap("assets/full.png")
	emptyPng1 = makeBitmap("assets/empty.png")
	emptyPng2 = makeBitmap("assets/empty.png")
	shovelPng1 = makeBitmap("assets/shovel.png")
	shovelPng2 = makeBitmap("assets/shovel.png")

	// headline at the top
	headline = makeText(false, 200, 10, 500, 50, 0x008000, "")

	// Explation text on the left
	makeText(false, 10, 140, 180, 200, 0x008000, `Both animated gophers are 
running the code on the right.
The 2 logos show where they
each are in that code now.
Go uses the tardsigolib/hx
package to call Haxe.`)

	// the code extract in the centre
	makeSprite(makeBitmap("assets/function.png"), 200, 110)

	// the "inspired by"" text
	makeText(true, 590, 140, 200, 200, 0x008000, `Inspired by Rob Pike:
"Concurrency is not Parallelism"
http://blog.golang.org/
concurrency-is-not-parallelism

- Gopher by Renee French`)

	// big pile of books on the left
	makeSprite(makeBitmap("assets/bigpile.png"), 10, 20)

	// oven on the right
	makeSprite(makeBitmap("assets/oven.png"), 690, 0)

	// books in the middle
	Books = makeSprite(emptyPilePng, 390, 50)

	// the left hand code indicator
	Logo1 = makeSprite(makeBitmap("assets/gophercolor16x16.png"), 230, 140)

	// the right hand code indicator
	Logo2 = makeSprite(makeBitmap("assets/gophercolor16x16flipped.png"), 540, 140)

	// the left hand gopher
	Sprite1 = makeSprite(pickPng1, s1x, s1y)

	// the right hand gopher
	Sprite2 = makeSprite(pickPng2, s2x, s2y)

	startGophers() // start the animation logic
	go monitor()   // monitor the state of the system on the display

	// now start an OpenFL timer to schedule this Go code to run every time a new frame is calculated
	hx.Meth("", mainThis, "", "addEventListener", 2,
		hx.GetDynamic("", "openfl.events.Event.ENTER_FRAME"),
		hx.GetDynamic("", "Scheduler.timerEventHandler"))
}

func replaceBitmap(sprite, bitmap *uintptr) { // pointers here to avoid a Haxe object copy when passing by value
	hx.Meth("", *sprite, "", "removeChildAt", 1, 0)
	hx.Meth("", *sprite, "", "addChild", 1, *bitmap)
}

func monitor() {
	showingBooks := false
	s1state, s2state := Pick, Pick
	time := -1 // invalid value, so that it always does not match 1st time through
	for {

		// put in the correct time, if we are on a new second
		tm := hx.GetInt("", "Date.now().getSeconds()")
		if time != tm {
			time = tm
			tms := hx.GetString("", "Date.now().toString()")
			hx.FsetString("", headline, "openfl.text.TextField", "text", "This is written in Go, translated go->haxe->"+tardisgolib.Platform()+
				", running live: "+tms)
		}

		// make the pile of books appear or disappear
		if len(smallpile) > 0 { // take the length of the channel here
			if !showingBooks {
				replaceBitmap(&Books, &smallPilePng)
				showingBooks = true
			}
		} else {
			if showingBooks {
				replaceBitmap(&Books, &emptyPilePng)
				showingBooks = false
			}
		}

		// animate left-hand sprite and it's code logo
		if s1state != Sprite1state {
			s1state = Sprite1state
			hx.FsetInt("", Logo1, "openfl.display.Sprite", "y", 140+(15*Sprite1state)) // move the logo to reflect the new state
			switch s1state {
			case Pick:
				replaceBitmap(&Sprite1, &pickPng1)
			case Full:
				replaceBitmap(&Sprite1, &fullPng1)
			case Shovel:
				replaceBitmap(&Sprite1, &shovelPng1)
			case Empty:
				replaceBitmap(&Sprite1, &emptyPng1)
			}
		}
		hx.FsetFloat("", Sprite1, "openfl.display.Sprite", "x", s1x+Sprite1X)
		hx.FsetFloat("", Sprite1, "openfl.display.Sprite", "y", s1y+Sprite1Y)

		// animate right-hand sprite and it's code logo
		if s2state != Sprite2state {
			s2state = Sprite2state
			hx.FsetInt("", Logo2, "openfl.display.Sprite", "y", 140+(15*Sprite2state)) // move the logo to reflect the new state
			switch s2state {
			case Pick:
				replaceBitmap(&Sprite2, &pickPng2)
			case Full:
				replaceBitmap(&Sprite2, &fullPng2)
			case Shovel:
				replaceBitmap(&Sprite2, &shovelPng2)
			case Empty:
				replaceBitmap(&Sprite2, &emptyPng2)
			}
		}
		hx.FsetFloat("", Sprite2, "openfl.display.Sprite", "x", s2x+Sprite2X)
		hx.FsetFloat("", Sprite2, "openfl.display.Sprite", "y", s2y+Sprite2Y)

		tardisgolib.Gosched() // give up control (NOTE Gosched creates a channel and selects from it)
	}
}
