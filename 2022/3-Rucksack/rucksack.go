package main

import (
	"bufio"
	"fmt"
	"os"
)

func fileToSlice(s string) ([]string, error) {
	file, err := os.Open(s)
	if err != nil {
		return nil, err
	}

	var s1 []string
	fs := bufio.NewScanner(file)
	fs.Split(bufio.ScanLines)

	for fs.Scan() {
		line := fs.Text()
		s1 = append(s1, line)
	}
	return s1, nil

}

func cutAndSearch(s []string) []string {
	var h1 []string
	var h2 []string
	var h3 []string
	var h4 []string

	for i := 0; i < len(s); i++ {
		sRune := []rune(s[i])

		//  Cut 1st half
		for j := 0; j < (len(sRune) / 2); j++ {
			c := string(sRune[j])
			h1 = append(h1, c)
		}

		// Cut 2nd half
		for o := (len(sRune) / 2); o < len(sRune); o++ {
			c := string(sRune[o])
			h2 = append(h2, c)
		}

		// Compare strings char by char
		for k := 0; k < len(h1); k++ {
			for p := 0; p < len(h2); p++ {
				if h1[k] == h2[p] {
					h3 = append(h3, h1[k])
				}
			}

		}
		if len(h3) > 0 {
			h4 = append(h4, h3[0])
		}

		h1, h2, h3 = nil, nil, nil

	}

	return h4
}

// This is ridiculous! but it works
func countPoints(s []string) int {
	sum := 0

	for i := 0; i < len(s); i++ {
		switch s[i] {
		case "a":
			sum += 1
		case "b":
			sum += 2
		case "c":
			sum += 3
		case "d":
			sum += 4
		case "e":
			sum += 5
		case "f":
			sum += 6
		case "g":
			sum += 7
		case "h":
			sum += 8
		case "i":
			sum += 9
		case "j":
			sum += 10
		case "k":
			sum += 11
		case "l":
			sum += 12
		case "m":
			sum += 13
		case "n":
			sum += 14
		case "o":
			sum += 15
		case "p":
			sum += 16
		case "q":
			sum += 17
		case "r":
			sum += 18
		case "s":
			sum += 19
		case "t":
			sum += 20
		case "u":
			sum += 21
		case "v":
			sum += 22
		case "w":
			sum += 23
		case "x":
			sum += 24
		case "y":
			sum += 25
		case "z":
			sum += 26
		case "A":
			sum += 27
		case "B":
			sum += 28
		case "C":
			sum += 29
		case "D":
			sum += 30
		case "E":
			sum += 31
		case "F":
			sum += 32
		case "G":
			sum += 33
		case "H":
			sum += 34
		case "I":
			sum += 35
		case "J":
			sum += 36
		case "K":
			sum += 37
		case "L":
			sum += 38
		case "M":
			sum += 39
		case "N":
			sum += 40
		case "O":
			sum += 41
		case "P":
			sum += 42
		case "Q":
			sum += 43
		case "R":
			sum += 44
		case "S":
			sum += 45
		case "T":
			sum += 46
		case "U":
			sum += 47
		case "V":
			sum += 48
		case "W":
			sum += 49
		case "X":
			sum += 50
		case "Y":
			sum += 51
		case "Z":
			sum += 52
		}
	}
	return sum

}

func cutAndSearch2(s []string) []string {
	var h1 []string
	var h2 []string
	var h3 []string
	var h4 []string
	var h5 []string

	for i := 0; i < len(s); i += 3 {
		rune1 := []rune(s[i])
		rune2 := []rune(s[i+1])
		rune3 := []rune(s[i+2])

		for j := 0; j < len(rune1); j++ {
			c := string(rune1[j])
			h1 = append(h1, c)
		}

		for o := 0; o < len(rune2); o++ {
			c := string(rune2[o])
			h2 = append(h2, c)
		}

		for k := 0; k < len(rune3); k++ {
			c := string(rune3[k])
			h3 = append(h3, c)
		}

		for p := 0; p < len(h1); p++ {
			for l := 0; l < len(h2); l++ {
				for u := 0; u < len(h3); u++ {
					if h1[p] == h2[l] && h1[p] == h3[u] {
						h4 = append(h4, h1[p])
					}
				}
			}
		}
		if len(h4) > 0 {
			h5 = append(h5, h4[0])
		}

		h1, h2, h3, h4 = nil, nil, nil, nil
	}

	return h5
}

func main() {
	f, err := fileToSlice("input")
	if err != nil {
		fmt.Println(err)
	}
	h3 := cutAndSearch(f)
	h4 := countPoints(h3)

	h5 := cutAndSearch2(f)
	h6 := countPoints(h5)

	fmt.Printf("Part 1 > %d\n", h4)
	fmt.Printf("Part 2 > %d\n", h6)
}
