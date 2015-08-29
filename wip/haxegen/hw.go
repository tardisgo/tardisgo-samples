package main

type haxeClassInst struct {
	class *haxeClass
	vars  map[string]interface{}
}
type haxeClass struct {
	__name__   []string
	vars       map[string]interface{}
	newInst    func([]interface{}) *haxeClassInst
	classMeths map[string]func(...interface{}) interface{}
	instMeths  map[string]func(...interface{}) interface{}
}

var hxClasses = make(map[string]*haxeClass)

// Haxe types
type type_HelloWorld struct {
	__name__ []string
	main     func()
}

var HelloWorld type_HelloWorld

func init() {
	//func() { }()
	HelloWorld.__name__ = []string{"HelloWorld"}
	// Statics
	HelloWorld.main = func() {
		hw := "Hello World"
		hw += "..."
		fortytwo := 84
		fortytwo = fortytwo/2 | 0
		println(hw)
		_g := 0
		for _g < 10 {
			i := _g
			_g++
			println(i)
		}
		println(fortytwo)
	}
	// Fields
} // end init()
type type_Std struct {
	__name__ []string
}

var Std type_Std

func init() {
	//func() { }()
	Std.__name__ = []string{"Std"}
	// Statics
	// Fields
} // end init()
// Haxe inits
func init() {
	{
	}
}

// Haxe statics
// Haxe expr
func main() {
	HelloWorld.main()
}
