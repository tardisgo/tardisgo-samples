package main

func main() {}

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

func MouseUp(x, y float64)   { mouseEvents <- mouseEvent{MOUSE_UP, x, y} }
func MouseDown(x, y float64) { mouseEvents <- mouseEvent{MOUSE_DOWN, x, y} }
func MouseMove(x, y float64) { mouseEvents <- mouseEvent{MOUSE_MOVE, x, y} }

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
