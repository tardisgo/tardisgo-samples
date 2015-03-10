// demonstrate ssa code generation bug
// issue discovered in http://golang.org/src/compress/flate/inflate.go:691
// when testing that package in https://github.com/tardisgo/tardisgo

package main

const (
	maxCodeLen = 16    // max length of Huffman code
	maxHist    = 32768 // max history required
	// The next three numbers come from the RFC, section 3.2.7.
	maxLit   = 286
	maxDist  = 32
	numCodes = 19 // number of codes in Huffman meta-code
)

// Decompress state.
type decompressor struct {
	// Input source.
	r       interface{} //Reader
	roffset int64
	woffset int64

	// Input bits, in top of b.
	b  uint32
	nb uint

	// Huffman decoders for literal/length, distance.
	h1, h2 interface{} //huffmanDecoder

	// Length arrays used to define Huffman codes.
	bits     *[maxLit + maxDist]int
	codebits *[numCodes]int

	// Output history, buffer.
	hist  *[maxHist]byte
	hp    int  // current output position in buffer
	hw    int  // have written hist[0:hw] already
	hfull bool // buffer has filled at least once

	// Temporary buffer (avoids repeated allocation).
	buf [4]byte

	// Next step in the decompression,
	// and decompression state.
	step     func(*decompressor)
	final    bool
	err      error
	toRead   []byte
	hl, hd   *decompressor //huffmanDecoder
	copyLen  int
	copyDist int
}

func (f *decompressor) ResetBad() { // abridged from the orginal version in the compress/flate package
	*f = decompressor{
		hist: f.hist,
	}
}

/* SSA:
# Name: (*main.decompressor).ResetBad
# Package: main
# Location: reset.go:60:24
# Locals:
#   0:	t0 decompressor
func (f *decompressor) ResetBad():
0:                                                                entry P:0 S:0
	t0 = local decompressor ()                                *decompressor
	t1 = *t0                                                   decompressor
	*f = t1
	t2 = &f.hist [#9]                                         **[32768]byte
	t3 = &f.hist [#9]                                         **[32768]byte
	t4 = *t3                                                   *[32768]byte
	*t2 = t4
	return
*/

func (f *decompressor) ResetOK() { // rewritten version using a temp var to make it work
	d := decompressor{
		hist: f.hist,
	}
	*f = d
}

/* SSA:
# Name: (*main.decompressor).ResetOK
# Package: main
# Location: reset.go:53:24
# Locals:
#   0:	t0 decompressor
#   1:	t1 decompressor
func (f *decompressor) ResetOK():
0:                                                                entry P:0 S:0
	t0 = local decompressor (d)                               *decompressor
	t1 = local decompressor ()                                *decompressor
	t2 = *t1                                                   decompressor
	*t0 = t2
	t3 = &t0.hist [#9]                                        **[32768]byte
	t4 = &f.hist [#9]                                         **[32768]byte
	t5 = *t4                                                   *[32768]byte
	*t3 = t5
	t6 = *t0                                                   decompressor
	*f = t6
	return
*/

func (f *decompressor) print() {
	for a := range f.hist {
		if a&0xff != int(f.hist[a]) {
			println("bad")
			return
		}
	}
	println("good")
}

func main() {
	anF := new(decompressor)
	anF.hist = new([maxHist]byte)
	for b := range anF.hist {
		anF.hist[b] = byte(b)
	}
	anF.print()
	anF.ResetOK()
	anF.print()
	anF.ResetBad()
	anF.print()
}
