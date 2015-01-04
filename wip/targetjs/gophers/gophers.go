// Rewrite of the animation at http://tardisgo.github.io for targeting JS directly via Haxe by @elliottstoneham who holds the copyright.

// Animation inspired by http://blog.golang.org/concurrency-is-not-parallelism.
// Gopher logo by Renée French. The design is licensed under the Creative Commons 3.0 Attributions license.
// For more details see http://blog.golang.org/gopher.

package main

import (
	//"strings"

	//_ "github.com/tardisgo/tardisgo/golibruntime/strings"

	. "github.com/tardisgo/gohaxelib/_js"
	"github.com/tardisgo/tardisgo/tardisgolib"
	"github.com/tardisgo/tardisgo/tardisgolib/hx"
)

var timer Shaxe_Timer // make sure it is a global variable

func main() {
	timer = Shaxe_Timer_new_1(100)                               // ms delay between each invocation
	hx.SetInt("", "Scheduler.runLimit", 10)                      // max times to run each goroutine (default is 1)
	timer.Srun_s(hx.CallbackFunc("Scheduler.timerEventHandler")) // set the code to run every time
	go Start()
}

// the globals below are inspected by the GopherJS interface code below to move and change sprites to create the animation
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
	smallpile = make(chan int, 1) // len() does not work in GopherJS without a length of 1
	oven = make(chan int)

	// now start off the two gophers
	go gopher(&Sprite1X, &Sprite1Y, &Sprite1state, bigpile, smallpile)
	go gopher(&Sprite2X, &Sprite2Y, &Sprite2state, smallpile, oven)

	go fire() // burn everything that arrives!

	bigpile <- 1     // start low, so that left-hand gopher moves fast
	smallpile <- 10  // start high, so that right-hand gopher moves slow
	go fillbigpile() // keep adding randomly to the big pile
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

// an individual gopher, animated with logos by the GopherJS code
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
	delay(v) // spend longer picking some loads and putting them on the cart
	return v
}
func pushBooks(x, y *float64, state *int, cartLoad int) {
	*state = Full
	for *x = 0.0; *x < 150.0; (*x) += 10.0 / float64(cartLoad) {
		if *y > 0.0 { // create bumps in the road
			*y = 0.0
		} else {
			*y = float64(SStd_random_1(3)) // random small bumps
		}
		Gosched() // without this, the animation would not show each state
	}
	if *x > 150.0 { // constrain large x offsets
		*x = 150.0
	}
	*y = 0.0
}
func fireBooks(x, y *float64, state *int, cartLoad int, out chan int) {
	*state = Shovel
	delay(cartLoad) // spend longer unloading some loads into the fire
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
			*y = float64(SStd_random_1(5)) // random bigger bumps
		}
		Gosched() // would not show state without this, the animation would jump.
	}
	*y = 0.0
}
func delay(n int) { // add some delay when required
	w := make(chan struct{})
	Shaxe_Timer_delay_2(func() {
		w <- struct{}{}
	}, n*250)
	<-w
}

/**** JS interface code ****/

var Books, Logo1, Logo2, Sprite1, Sprite2 *Sprite

const (
	s1x = 90
	s1y = 45
	s2x = 420
	s2y = 45
)

func makeText(selectable bool, x, y, width, height, textColor int, oldtext, text string) {
	context.SfillStyle_s(hx.GetDynamic("", `'#fff'`))
	context.SfillText_3(oldtext, float64(x), float64(y))
	context.SfillStyle_s(hx.GetDynamic("", `'#373'`))
	context.Sfont_s("12px Arial")
	ss := make([]string, 1)
	for _, v := range text {
		if v == '\n' {
			ss = append(ss, "")
		} else {
			ss[len(ss)-1] += string(v)
		}
	}
	for k, v := range ss {
		context.SfillText_3(v, float64(x), float64(y+(12*k)))
	}
}

func makeBitmap(file string) Sjs_html_Image {
	img := Sjs_html_Image_new_0() //js.Global.Get("Image").New()
	img.Ssrc_s(file)              //img.Set("src", file)
	return img
}

type Sprite struct {
	bitmap Sjs_html_Image
	x, y   int
}

var spChan = make(chan *Sprite)

func makeSprite(bitmap Sjs_html_Image, x, y int) *Sprite {
	if bitmap.Scomplete_g() {
		context.SdrawImage_3(bitmap, x, y) //context.Call("drawImage", bitmap, x, y)
	} else {
		bitmap.Sonload_s(func(e uintptr) {
			context.SdrawImage_3(bitmap, x, y)
		})
	}
	return &Sprite{
		bitmap: bitmap,
		x:      x,
		y:      y,
	}
}

var doc Sjs_html_Document

var emptyPilePng, smallPilePng, pickPng1, pickPng2, fullPng1, fullPng2, emptyPng1, emptyPng2, shovelPng1, shovelPng2, white, L1, L2, WT Sjs_html_Image

var context Sjs_html_CanvasRenderingContext2D

var lastTime int

var lastHeading string

// headline at the top
func makeHeadline(e uintptr) {
	now := SDate_now_0()

	if now.SgetSeconds_0() != lastTime {
		nextHeading := "Translated by TARDIS Go into JS and running live: " +
			now.StoString_0()
		makeText(false, 195, 15, 500, 20, 0x008000, lastHeading, nextHeading)
		lastTime = now.SgetSeconds_0()
		lastHeading = nextHeading
	}
}

var headlineTimer Shaxe_Timer

func Start() {
	doc = Sjs_Browser_document_g()            //js.Global.Get("document")
	temp := doc.SgetElementById_1("myCanvas") //doc.Call("getElementById", "myCanvas")
	// uintptr in order to cast via Haxe Dynamic
	var canvas Sjs_html_CanvasElement
	canvas = Sjs_html_CanvasElement(temp)
	context = canvas.SgetContext2d_0() //canvas.Call("getContext", "2d")

	// big pile of books on the left - sequencing not important so in goroutine
	go func() { makeSprite(makeBitmap("assets/bigpile.png"), 10, 20) }()
	// oven on the right - sequencing not important so in goroutine
	go func() { makeSprite(makeBitmap("assets/oven.png"), 690, 0) }()

	// setup the animated PNG bitmaps, in the order of 1st use
	codePNG := makeBitmap("assets/function.png")
	emptyPilePng = makeBitmap("assets/emptypile.png")
	L1 = makeBitmap("assets/gophercolor16x16.png")
	L2 = makeBitmap("assets/gophercolor16x16flipped.png")
	pickPng1 = makeBitmap("assets/pick.png")
	pickPng2 = makeBitmap("assets/pick.png")
	smallPilePng = makeBitmap("assets/smallpile.png")
	fullPng1 = makeBitmap("assets/full.png")
	fullPng2 = makeBitmap("assets/full.png")
	emptyPng1 = makeBitmap("assets/empty.png")
	emptyPng2 = makeBitmap("assets/empty.png")
	shovelPng1 = makeBitmap("assets/shovel.png")
	shovelPng2 = makeBitmap("assets/shovel.png")
	white = makeBitmap("assets/white.png")
	WT = makeBitmap("assets/whitethumb.png")

	makeHeadline(0)
	headlineTimer = Shaxe_Timer_new_1(1000) // fire every second
	headlineTimer.Srun_s(makeHeadline)

	// Explation text on the left
	makeText(false, 10, 140, 180, 200, 0x008000, "", `Both animated gophers are 
running the code on the right.
The 2 logos show where they
each are in that code now.

Go calling native JS APIs.`)

	// the "inspired by"" text
	makeText(true, 630, 140, 200, 200, 0x008000, "", `Inspired by Rob Pike:
http://blog.golang.org/
concurrency-is-not-parallelism

Gopher by Renee French,
Creative Commons 3.0 license`)

	// the code extract in the centre
	makeSprite(codePNG, 200, 110)

	// books in the middle
	Books = makeSprite(emptyPilePng, 390, 50)

	// the left hand code indicator
	Logo1 = makeSprite(L1, 230, 140)

	// the right hand code indicator
	Logo2 = makeSprite(L2, 540, 140)

	// the left hand gopher
	Sprite1 = makeSprite(pickPng1, s1x, s1y)

	// the right hand gopher
	Sprite2 = makeSprite(pickPng2, s2x, s2y)

	startGophers() // start the animation logic

}

func replaceBitmap(sprite *Sprite, bitmap *Sjs_html_Image) {
	sprite.bitmap = *bitmap
	context.SdrawImage_3(sprite.bitmap, sprite.x, sprite.y) //Call("drawImage", sprite.bitmap, sprite.x, sprite.y)
}

var showingBooks bool = true

var s1state, s2state int = Pick, Pick

func monitor() {

	// make the pile of books appear or disappear
	if len(smallpile) > 0 { // take the length of the channel here
		if !showingBooks {
			replaceBitmap(Books, &smallPilePng)
			showingBooks = true
		}
	} else {
		if showingBooks {
			replaceBitmap(Books, &emptyPilePng)
			showingBooks = false
		}
	}

	// animate left-hand sprite and it's code logo
	newY1 := 140 + (15 * Sprite1state) // move the logo to reflect the new state
	if Logo1.y != newY1 {
		replaceBitmap(Logo1, &WT)
		Logo1.y = newY1
		replaceBitmap(Logo1, &L1)
	}
	if s1state != Sprite1state {
		switch s1state {
		case Shovel, Pick:
			replaceBitmap(Sprite1, &white)
		}
		s1state = Sprite1state
	}
	newS1X := int(s1x + Sprite1X)
	newS1Y := int(s1y + Sprite1Y)
	if Sprite1.x != newS1X || Sprite1.y != newS1Y {
		Sprite1.x = newS1X
		Sprite1.y = newS1Y
		switch Sprite1state {
		case Pick:
			replaceBitmap(Sprite1, &pickPng1)
		case Full:
			replaceBitmap(Sprite1, &fullPng1)
		case Shovel:
			replaceBitmap(Sprite1, &shovelPng1)
		case Empty:
			replaceBitmap(Sprite1, &emptyPng1)
		}
	}

	// animate right-hand sprite and it's code logo
	newY2 := 140 + (15 * Sprite2state) // move the logo to reflect the new state
	if Logo2.y != newY2 {
		replaceBitmap(Logo2, &WT)
		Logo2.y = newY2
		replaceBitmap(Logo2, &L2)
	}
	if s2state != Sprite2state {
		switch s2state {
		case Shovel, Pick:
			replaceBitmap(Sprite2, &white)
		}
		s2state = Sprite2state
	}
	newS2X := int(s2x + Sprite2X)
	newS2Y := int(s2y + Sprite2Y)
	if Sprite2.x != newS2X || Sprite2.y != newS2Y {
		Sprite2.x = newS2X
		Sprite2.y = newS2Y
		switch Sprite2state {
		case Pick:
			replaceBitmap(Sprite2, &pickPng2)
		case Full:
			replaceBitmap(Sprite2, &fullPng2)
		case Shovel:
			replaceBitmap(Sprite2, &shovelPng2)
		case Empty:
			replaceBitmap(Sprite2, &emptyPng2)
		}
	}

}

// Gosched here both monitors what is going on, displaying changes to the observer and schedules other goroutines
func Gosched() {
	monitor()
	tardisgolib.Gosched()
}
