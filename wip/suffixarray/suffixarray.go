package main

import "index/suffixarray"

func main() {
	data := []byte("this os is darwin, what is this os? Oh, this os is ostrich!")
	s := []byte("os")

	// create index for some data
	index := suffixarray.New(data)

	// lookup byte slice s
	offsets1 := index.Lookup(s, -1) // the list of all indices where s occurs in data
	offsets2 := index.Lookup(s, 3)  // the list of at most 3 indices where s occurs in data
	for i := range offsets1 {
		println(i, offsets1[i])
	}
	for i := range offsets2 {
		println(i, offsets2[i])
	}
}
