package main

import (
	"bytes"
	"io/ioutil"
)

var replacements = [][][]byte{
	{[]byte("\twhile("), []byte("\tfor(")},
}

func main() {

	rawJS, err := ioutil.ReadFile("hw.js")
	if err != nil {
		panic(err)
	}

	rawGo := make([]byte, 0, len(rawJS))

	linesJS := bytes.Split(rawJS, []byte("\n"))
	for _, line := range linesJS {
		for _, rep := range replacements {
			if bytes.Contains(line, rep[0]) {
				line = bytes.Replace(line, rep[0], rep[1], 1)
			}
		}
		if bytes.Contains(line, []byte("\tvar ")) &&
			bytes.Contains(line, []byte(" = ")) {
			line = bytes.Replace(line, []byte("\tvar "), []byte("\t"), 1)
			line = bytes.Replace(line, []byte(" = "), []byte(" := "), 1)
		}
		if bytes.HasSuffix(line, []byte("++;")) {
			pos := len(line) - 3
			end := pos
			for line[pos] != ' ' {
				pos--
			}
			v := line[pos:end]
			println("v:" + string(v))
			rawGo = append(rawGo, line[:end]...)
			line = nil
			rawGo = append(rawGo, byte('\n'))
			rawGo = append(rawGo, v...)
			rawGo = append(rawGo, []byte("++;")...)
		}

		rawGo = append(rawGo, line...)
		rawGo = append(rawGo, []byte("\n")...)
	}
	ioutil.WriteFile("hw.go", rawGo, 0666)
}
