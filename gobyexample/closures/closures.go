// adapted from https://gobyexample.com/closures

// Go supports [_anonymous functions_](http://en.wikipedia.org/wiki/Anonymous_function),
// which can form <a href="http://en.wikipedia.org/wiki/Closure_(computer_science)"><em>closures</em></a>.
// Anonymous functions are useful when you want to define
// a function inline without having to name it.

package main

//import "fmt"

// This function `intSeq` returns another function, which
// we define anonymously in the body of `intSeq`. The
// returned function _closes over_ the variable `i` to
// form a closure.
func intSeq() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
}

func main() {

	// We call `intSeq`, assigning the result (a function)
	// to `nextInt`. This function value captures its
	// own `i` value, which will be updated each time
	// we call `nextInt`.
	nextInt := intSeq()

	// See the effect of the closure by calling `nextInt`
	// a few times.
	println(nextInt())
	println(nextInt())
	println(nextInt())

	// To confirm that the state is unique to that
	// particular function, create and test a new one.
	newInts := intSeq()
	println(newInts())

}
