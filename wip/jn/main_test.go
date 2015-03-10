package main

import (
	"math"
	"testing"
)

var vf = []float64{
	4.9790119248836735e+00,
	7.7388724745781045e+00,
	-2.7688005719200159e-01,
	-5.0106036182710749e+00,
	9.6362937071984173e+00,
	2.9263772392439646e+00,
	5.2290834314593066e+00,
	2.7279399104360102e+00,
	1.8253080916808550e+00,
	-8.6859247685756013e+00,
}

var yM3 = []float64{
	-0.14035984421094849100895341,
	-0.097535139617792072703973,
	242.25775994555580176377379,
	-0.1492267014802818619511046,
	0.26148702629155918694500469,
	0.56675383593895176530394248,
	-0.206150264009006981070575,
	0.64784284687568332737963658,
	1.3503631555901938037008443,
	0.1461869756579956803341844,
}

func TestYn(t *testing.T) {
	//t.Skip("Yn test fails - TODO")
	//return
	for i := 0; i < len(vf); i++ {
		a := math.Abs(vf[i])
		//if f := Yn(2, a); !close(y2[i], f) {
		//	t.Errorf("Yn(2, %g) = %g, want %g", a, f, y2[i])
		//}
		if f := myYn(-3, a); !close(yM3[i], f) {
			t.Errorf("Yn(-3, %g) = %g, want %g", a, f, yM3[i])
		}
	}
	/*
		for i := 0; i < len(vfy0SC); i++ {
			if f := Yn(2, vfy0SC[i]); !alike(y2SC[i], f) {
				t.Errorf("Yn(2, %g) = %g, want %g", vfy0SC[i], f, y2SC[i])
			}
			if f := Yn(-3, vfy0SC[i]); !alike(yM3SC[i], f) {
				t.Errorf("Yn(-3, %g) = %g, want %g", vfy0SC[i], f, yM3SC[i])
			}
		}
	*/
}
func tolerance(a, b, e float64) bool {
	d := a - b
	if d < 0 {
		d = -d
	}

	if a != 0 {
		e = e * a
		if e < 0 {
			e = -e
		}
	}
	return d < e
}
func kindaclose(a, b float64) bool { return tolerance(a, b, 1e-8) }
func close(a, b float64) bool      { return tolerance(a, b, 1e-14) }
func veryclose(a, b float64) bool  { return tolerance(a, b, 4e-16) }
func soclose(a, b, e float64) bool { return tolerance(a, b, e) }
func alike(a, b float64) bool {
	switch {
	case math.IsNaN(a) && math.IsNaN(b):
		return true
	case a == b:
		return math.Signbit(a) == math.Signbit(b)
	}
	return false
}
