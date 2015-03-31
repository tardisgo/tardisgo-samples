package main

var a = []int{42}

func main() {
	printInt(a)
}

func printInt(i interface{}) {
	println(i.([]int)[0])
}
