// from http://spf13.com/presentation/go-for-object-oriented-programmers
package main

type Person struct {
	Name string
	Address
}

type Address struct {
	Number string
	Street string
	City   string
	State  string
	Zip    string
}

func (a *Address) String() string {
	return a.Number + " " + a.Street + "\n" + a.City + ", " + a.State + " " + a.Zip + "\n"
}

func main() {
	p := Person{
		Name: "Steve",
		Address: Address{
			Number: "13",
			Street: "Main",
			City:   "Gotham",
			State:  "NY",
			Zip:    "01313",
		},
	}

	println(p.Street != "", p.String())
}
