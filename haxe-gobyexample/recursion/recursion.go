package main // example inspired by gobyexample.com/recursion

func fact(n int) int {
	if n == 0 {
		return 1
	}
	return n * fact(n-1)
}

func main() {
	println("ten factorial is ", fact(10)) // NOTE fmt package not implemented in TARDIS Go as at Jan'14
}
