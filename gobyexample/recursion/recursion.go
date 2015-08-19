package main // example inspired by gobyexample.com/recursion
import "fmt"

func fact(n int) int {
	if n == 0 {
		return 1
	}
	return n * fact(n-1)
}

func main() {
	fmt.Println("ten factorial is ", fact(10))
}
