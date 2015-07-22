package main

import (
	"log"
	"net/http"
)

func main() {
	println("Simple static webserver running on port 8080 serving current directory")
	log.Fatal(http.ListenAndServe(":8080", http.FileServer(http.Dir("."))))
}
