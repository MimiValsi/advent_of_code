package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func fileToSlice(s string) ([]string, error) {
	file, err := os.Open(s)
	if err != nil {
		return nil, err
	}

	var str1 []string
	fs := bufio.NewScanner(file)
	fs.Split(bufio.ScanLines)

	for fs.Scan() {
		line := fs.Text()
		str1 = append(str1, line)
	}
	return str1, nil

}

func separateLines(s []string) []string {
	var str1 []string
	for i := 0; i < len(s); i++ {
		temp := strings.Split(s[i], ",")

		str1 = append(str1, temp...)

	}

	return str1
}

func countPairs(s []string) (int, int) {
	var str1 []string

	for i := 0; i < len(s); i++ {
		temp2 := strings.Split(s[i], "-")

		str1 = append(str1, temp2...)
	}

	sum := 0
	sum2 := 0
	for i := 0; i < len(str1); i += 4 {
		s1, _ := strconv.Atoi(str1[i])
		e1, _ := strconv.Atoi(str1[i+1])
		s2, _ := strconv.Atoi(str1[i+2])
		e2, _ := strconv.Atoi(str1[i+3])

		// Pair that are fully contain other pair
		if (s2 <= s1 && e1 <= e2) || (s1 <= s2 && e2 <= e1) {
			sum++
			// break
		}
		// Overlap:
		// 	s2 ---- e2
		//   e1 ---------- s1
		if !(e1 < s2 || s1 > e2) {
			sum2++
		}
	}

	return sum, sum2
}

func main() {
	file, err := fileToSlice("input")
	if err != nil {
		fmt.Println(err)
	}

	t := separateLines(file)
	sum, sum2 := countPairs(t)
	fmt.Println(sum)
	fmt.Println(sum2)
}
