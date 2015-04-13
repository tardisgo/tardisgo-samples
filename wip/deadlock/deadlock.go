// from https://groups.google.com/d/msg/golang-nuts/DK_Cl0FgblA/WYnoO1cIo28J
// You can edit this code!
// Click here and start typing.
package main

import "fmt"
import "runtime"

func Test4() {
	runtime.GOMAXPROCS(8)
	cPop := make(chan int, 1)
	cPush := make(chan int, 1)
	cCache := make(chan int, 100)

	n := 1
	cPush <- n
	fmt.Printf("PUSH\t=>Push:%v\n", 1)
	go func() {
		for {
			fmt.Printf("\tFor Start\t=>:cPop:%+v,cPush:%+v,cCache:%+v\n", len(cPop), len(cPush), len(cCache))
			select {
			case n = <-cPush:
				cPop <- n
				fmt.Printf("\t\tSELECT\t=>cPop <- %v <- cPush\n", n)
			case n = <-cCache:
				cPop <- n
				fmt.Printf("\t\tSELECT\t=>cPop <- %v <- cCache\n", n)
			case n = <-cPush:
				cCache <- n
				fmt.Printf("\t\tSELECT\t=>cCache <- %v <- cPush\n", n)
			}
			fmt.Printf("\tFor End\t=>:cPop:%+v,cPush:%+v,cCache:%+v\n", len(cPop), len(cPush), len(cCache))
		}
	}()
	n = <-cPop
	fmt.Printf("POP\t=>Pop:%v\n", n)
}

func Test5() {
	runtime.GOMAXPROCS(8)
	cPop := make(chan int, 1)
	cPush := make(chan int, 1)
	cCache := make(chan int, 100)

	n := 1
	cPush <- n
	fmt.Printf("PUSH\t=>Push:%v\n", 1)
	go func() {
		for {
			fmt.Printf("\tFor Start\t=>:cPop:%+v,cPush:%+v,cCache:%+v\n", len(cPop), len(cPush), len(cCache))
			select {
			case cPop <- <-cPush:
				fmt.Printf("\t\tSELECT\t=>cPop <- %v <- cPush\n", n)
			case cPop <- <-cCache:
				fmt.Printf("\t\tSELECT\t=>cPop <- %v <- cCache\n", n)
			case cCache <- <-cPush:
				fmt.Printf("\t\tSELECT\t=>cCache <- %v <- cPush\n", n)
			}
			fmt.Printf("\tFor End\t=>:cPop:%+v,cPush:%+v,cCache:%+v\n", len(cPop), len(cPush), len(cCache))
		}
	}()
	n = <-cPop
	fmt.Printf("POP\t=>Pop:%v\n", n)
}

func Test5a() {
	runtime.GOMAXPROCS(8)
	cPop := make(chan int, 1)
	cPush := make(chan int, 1)
	cCache := make(chan int, 100)

	n := 1
	cPush <- n
	fmt.Printf("PUSH\t=>Push:%v\n", 1)
	go func() {
		for {
			fmt.Printf("\tFor Start\t=>:cPop:%+v,cPush:%+v,cCache:%+v\n", len(cPop), len(cPush), len(cCache))
			temp1 := <-cPush
			fmt.Println("Read temp1")
			temp2 := <-cCache // blocks forever here
			fmt.Println("Read temp2")
			temp3 := <-cPush
			fmt.Println("Read temp3")
			select {
			case cPop <- temp1:
				fmt.Printf("\t\tSELECT\t=>cPop <- %v <- cPush\n", n)
			case cPop <- temp2:
				fmt.Printf("\t\tSELECT\t=>cPop <- %v <- cCache\n", n)
			case cCache <- temp3:
				fmt.Printf("\t\tSELECT\t=>cCache <- %v <- cPush\n", n)
			}
			fmt.Printf("\tFor End\t=>:cPop:%+v,cPush:%+v,cCache:%+v\n", len(cPop), len(cPush), len(cCache))
		}
	}()
	n = <-cPop
	fmt.Printf("POP\t=>Pop:%v\n", n)
}

func main() {
	//test is ok
	Test4()
	//elliott addition
	Test5a()
	//fatal error: all goroutines are asleep - deadlock!
	Test5()
}
