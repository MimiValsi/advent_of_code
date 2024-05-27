package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)


func main() {
        // visible := 0

        f, _ := os.Open("test")
        defer f.Close()

        fs := bufio.NewScanner(f)
        
        for fs.Scan() {
                line := strings.Fields(fs.Text())
        }
        
}

func sliceToInt(line []string) []int {
        sInt := []int{}

        for v := range line {
                tmp := line[v]
                fmt.Printf("tmp: %s", tmp)
                break
        }

        return sInt
}
