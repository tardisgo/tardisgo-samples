package main

import (
	"fmt"
	"time"
)

type A interface {
	RunA(param string) string
	RunB(param string) string
}

type impl struct{}

func (impl) RunA(param string) string {
	return "ran A: " + param
}

func (impl) RunB(param string) string {
	return "ran B: " + param
}

func execute(on A, runner func(A, string) string) string {
	return runner(on, "hey!")
}

func makeItAdd(i, j, k int) func([]int) {
	return func(vars []int) {
		vars[k] = vars[i] + vars[j]
	}
}

func justAdd(vars []int, i, j, k int) {
	vars[k] = vars[i] + vars[j]
}

const TIMES = 1000000

func main() {
	fmt.Println("Hello, 世界")
	regs := make([]int, 100)
	fn := makeItAdd(1, 2, 3)
	regs[1] = 42
	regs[2] = 24
	start := time.Now()
	for i := 0; i < TIMES; i++ {
		fn(regs)
	}
	fmt.Println("made fn result", regs[3], "time", time.Since(start).Nanoseconds())
	start2 := time.Now()
	for i := 0; i < TIMES; i++ {
		justAdd(regs, 1, 2, 3)
	}
	fmt.Println("direct  result", regs[3], "time", time.Since(start2).Nanoseconds())
	fmt.Println(execute(impl{}, A.RunA))
	fmt.Println(execute(impl{}, A.RunB))
	fmt.Println(A.RunB(impl{}, "Elliott"))
}
