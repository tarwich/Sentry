package main

import (
	"fmt"
	"log"
	"os"
	"time"
)

const logFile = "/usr/local/clamXav/share/clamav/freshclam.log"

func main() {
	for {
		if err := os.Chtimes(logFile, time.Now(), time.Now()); err != nil {
			log.Fatal(err)
		} else {
			fmt.Println("Modified file", logFile)
		}
		time.Sleep(60 * time.Second)
	}
}
