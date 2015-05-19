package main

type S struct {
	B bool
}

func main() {
	a := S{true}
	if b := (S{true}); true { // brackets should not be required... !
		println("test", a, b)
	}
}
