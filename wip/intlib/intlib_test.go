// see http://golangtutorials.blogspot.co.uk/2011/10/gotest-unit-testing-and-benchmarking-go.html

package intlib //same package name as source file

import (
	"io/ioutil"

	"testing" //import go package for testing related functionality
)

func TestAdd2Ints_1(t *testing.T) { //test function starts with "Test" and takes a pointer to type testing.T
	if Add2Ints(3, 4) != 7 { //try a unit test on function
		t.Error("Add2Ints did not work as expected.") // log error if it did not work as expected
	} else {
		t.Log("one test passed.") // log some info if you want
	}
}

func TestAdd2Ints_2(t *testing.T) { //test function starts with "Test" and takes a pointer to type testing.T
	fi, err := ioutil.ReadDir("/test")
	if err != nil {
		t.Error("/test ReadDir read-back problem: " + err.Error())
	} else {
		for _, f := range fi {
			fn := "/test/" + f.Name()
			buf, err := ioutil.ReadFile(fn)
			if err != nil {
				t.Error(fn + " read-back ERROR! " + err.Error())
			} else {
				t.Log(fn + " -> " + string(buf))
			}
		}
	}
	log, err := ioutil.ReadFile("/unzipfs.log")
	if err != nil {
		println("/unzipfs.log read-back problem: " + err.Error())
	} else {
		println("/unzipfs.log -> " + string(log))
	}
}
