package main

import (
	"runtime"

	. "github.com/tardisgo/gohaxelib/_openfl"
)

func main() {} // see Main.hx for the starting point of this code

type mouseEvent struct {
	event int
	x     float64
	y     float64
}

const (
	MOUSE_UP = iota
	MOUSE_DOWN
	MOUSE_MOVE
)

var mouseEvents = make(chan mouseEvent, 100)

// The next three functions are all called by Haxe interface event handlers
func MouseUp(x, y float64) {
	//println("MOUSE UP", x, y)
	handleMouseEvent(mouseEvent{MOUSE_UP, x, y})
}
func MouseDown(x, y float64) {
	//println("MOUSE DOWN", x, y)
	handleMouseEvent(mouseEvent{MOUSE_DOWN, x, y})
}
func MouseMove(x, y float64) {
	//println("MOUSE MOVE", x, y)
	handleMouseEvent(mouseEvent{MOUSE_MOVE, x, y})
}

func handleMouseEvent(e mouseEvent) {
	if e.x < 1 || e.y < 1 {
		//println("BAD XY")
		return
	}
	mouseEvents <- e
}

// This function is called to set-up the mouse handling
func MouseGoroutine() {
	go handleMouse()
}

var SpriteX, SpriteY, cacheOffsetX, cacheOffsetY float64
var Status string

func init() {
	SpriteX = 100.0
	SpriteY = 150.0
}

func handleMouse() {
	for {
		e := <-mouseEvents
		switch e.event {
		case MOUSE_DOWN:
			Status = "MOUSE_DOWN"
			cacheOffsetX = SpriteX - e.x
			cacheOffsetY = SpriteY - e.y
			awaitingMouseUp := true
			for awaitingMouseUp {
				e = <-mouseEvents
				switch e.event {
				case MOUSE_MOVE:
					Status = "MOUSE_MOVE"
					SpriteX = e.x + cacheOffsetX
					SpriteY = e.y + cacheOffsetY
				case MOUSE_UP:
					Status = "MOUSE_UP"
					awaitingMouseUp = false
				default:
					Status = "awaiting MOUSE_UP"
				}
			}
		default:
			Status = "awaiting MOUSE_DOWN"
		}
	}
}

/*************************************** Haxe/OpenFL interface code *************************************/

var mainThis, Logo Xopenfl_display_Sprite
var XtextField Xopenfl_text_TextField

func Start(mt Xopenfl_display_Sprite) {
	mainThis = mt // this is actually a Haxe object, therefore a pointer

	SoundNew()

	whatToDo := Xopenfl_text_TextField_new_0()
	whatToDo.Xselectable_s(false)
	whatToDo.Xx_s(50)
	whatToDo.Xy_s(90)
	whatToDo.Xwidth_s(350)
	whatToDo.Xtext_s("USE YOUR MOUSE TO PUT THE GOPHER IN THE BOX")
	whatToDo.XtextColor_s(0xff0000)
	mt.XaddChild_1(whatToDo)

	Code := Xopenfl_display_Sprite_new_0()
	Code.XaddChild_1(Xopenfl_display_Bitmap_new_1(Xopenfl_Assets_getBitmapData_1("assets/code.png")))
	Code.Xx_s(400)
	Code.Xy_s(10)
	mt.XaddChild_1(Code)

	Logo = Xopenfl_display_Sprite_new_0()
	Logo.XaddChild_1(Xopenfl_display_Bitmap_new_1(Xopenfl_Assets_getBitmapData_1("assets/gopher.png")))
	Logo.Xx_s(100)
	Logo.Xy_s(150)
	Logo.XbuttonMode_s(true)

	Destination := Xopenfl_display_Sprite_new_0()
	gr := Destination.Xgraphics_g()
	gr.XbeginFill_2(0xF5F5F5, 1.0)
	gr.XlineStyle_2(1, 0xCCCCCC)
	gr.XdrawRect_4(0, 0, Logo.Xwidth_g()+10, Logo.Xheight_g()+10)
	Destination.Xx_s(300)
	Destination.Xy_s(145)

	XtextField = Xopenfl_text_TextField_new_0()
	XtextField.Xselectable_s(false)
	XtextField.Xx_s(305)
	XtextField.Xy_s(260)
	XtextField.Xwidth_s(200)
	XtextField.XtextColor_s(0x008000)
	XtextField.Xtext_s("(initialising)")
	mt.XaddChild_1(XtextField)
	mt.XaddChild_1(Destination)
	mt.XaddChild_1(Logo) // logo to pass over destination and text field

	Logo.XaddEventListener_2(Xopenfl_events_MouseEvent_MOUSE___DOWN_g(), Logo_onMouseDown)
	stage := mt.Xstage_g()
	stage.XaddEventListener_2(Xopenfl_events_MouseEvent_MOUSE___MOVE_g(), Stage_onMouseMove)
	stage.XaddEventListener_2(Xopenfl_events_MouseEvent_MOUSE___UP_g(), Stage_onMouseUp)

	MouseGoroutine()                                     // start the mouse handling goroutine
	goTimerBG := Xopenfl_utils_Timer_new_1(20)           // ms
	goTimerBG.XaddEventListener_2("timer", goTimerEvent) // schedule some go every so oftern
	goTimerBG.Xstart_0()

}

var goTimer Xopenfl_utils_Timer
var UseGopher bool = true
var lastStatus string

func goTimerEvent(e uintptr) {
	Logo.Xx_s(SpriteX) // set the X and Y sprite values
	Logo.Xy_s(SpriteY)
	if lastStatus != Status { // change the Go status code if required
		lastStatus = Status
		XtextField.Xtext_s(lastStatus)
	}
	if Logo.Xx_g() > 300 && Logo.Xx_g() < (300+Logo.Xwidth_g()) &&
		Logo.Xy_g() > 145 && Logo.Xy_g() < (145+Logo.Xheight_g()) { // this is just to make it look & sound pretty
		if UseGopher {
			Logo.XaddChild_1(Xopenfl_display_Bitmap_new_1(Xopenfl_Assets_getBitmapData_1("assets/openfl.png")))
			UseGopher = false
		}
		Play()
	} else {
		if !UseGopher {
			Logo.XaddChild_1(Xopenfl_display_Bitmap_new_1(Xopenfl_Assets_getBitmapData_1("assets/gopher.png")))
			UseGopher = true
		}
		Pause()
	}
}

// Sound handling

var channel Xopenfl_media_SoundChannel
var playing bool
var sound Xopenfl_media_Sound

func SoundNew() {
	if runtime.GOARCH == "flash" {
		sound = Xopenfl_Assets_getSound_1("assets/yeah.mp3")
	} else {
		sound = Xopenfl_Assets_getSound_1("assets/yeah.ogg")
	}
}

func Play() {
	if playing != true {
		playing = true
		channel = sound.Xplay_0()
	}
}

func Pause() {
	if playing {
		playing = false
		channel.Xstop_0()
	}
}

// Mouse Events

func Logo_onMouseDown(event Xopenfl_events_MouseEvent) {
	MouseDown(event.XstageX_g(), event.XstageY_g())
}

func Stage_onMouseUp(event Xopenfl_events_MouseEvent) {
	MouseUp(event.XstageX_g(), event.XstageY_g())
}
func Stage_onMouseMove(event Xopenfl_events_MouseEvent) {
	MouseMove(event.XstageX_g(), event.XstageY_g())
}

// Utils

type Stringer interface {
	String() string
}
