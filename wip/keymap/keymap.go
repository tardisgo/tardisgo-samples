package main

type Key [2]int

func main() {
	m := map[Key]int{
		Key{1, 2}: 3,
	}
	println("m=", m, "m[Key{1, 2}]=", m[Key{1, 2}])
}
