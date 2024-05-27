package main

import (
	"bufio"
	"fmt"
	"os"
)

// Rock > Scissors
// Paper > Rock
// Scissors > Paper

// Column 1
// A - Rock
// B - Paper
// C - Scissors

// Column 2
// X - Rock
// Y - Paper
// Z - Scissors

// Score
// Rock     = 1
// Paper    = 2
// Scissors = 3

// Rount Points
// Lost = 0
// Draw = 3
// Win  = 6

// Part 2
// X = lose = 0
// Y = draw = 3
// Z = win = 6

func fileToSlice(s string) ([]string, error) {
	file, err := os.Open(s)
	if err != nil {
		return nil, err
	}

	var s1 []string
	fs := bufio.NewScanner(file)
	fs.Split(bufio.ScanWords)

	for fs.Scan() {
		line := fs.Text()
		s1 = append(s1, line)
	}
	return s1, nil

}

func rockPaperScissors(s []string) int { // Part 1
	me := 0
	rock := 1
	paper := 2
	scissors := 3
	draw := 3
	win := 6

	for i := 0; i < len(s); i += 2 {
		if s[i] == "A" && s[i+1] == "X" { // Rock == Rock => Draw
			me += draw + rock
		} else if s[i] == "A" && s[i+1] == "Y" { // Rock < Paper => Win
			me += win + paper
		} else if s[i] == "A" && s[i+1] == "Z" { // Scissors points
			me += scissors
		} else if s[i] == "B" && s[i+1] == "Z" { // Paper < Scissors => Win
			me += win + scissors
		} else if s[i] == "B" && s[i+1] == "Y" { // Paper == Paper => Draw
			me += draw + paper
		} else if s[i] == "B" && s[i+1] == "X" { // Rock point
			me += rock
		} else if s[i] == "C" && s[i+1] == "X" { // Scissors < Rock => Win
			me += win + rock
		} else if s[i] == "C" && s[i+1] == "Z" { // Scissors == Scissors => Draw
			me += draw + scissors
		} else if s[i] == "C" && s[i+1] == "Y" { // Paper points
			me += paper
		}
	}

	return me
}

func rockPaperScissors2(s []string) int { // Part 1
	me := 0
	rock := 1
	paper := 2
	scissors := 3
	draw := 3
	win := 6

	for i := 0; i < len(s); i += 2 {
		if s[i] == "A" && s[i+1] == "X" { // Rock & Lose
			me += scissors
		} else if s[i] == "A" && s[i+1] == "Y" { // Rock & Draw
			me += draw + rock
		} else if s[i] == "A" && s[i+1] == "Z" { // Rock & Win
			me += win + paper
		} else if s[i] == "B" && s[i+1] == "Z" { // Paper & Win
			me += win + scissors
		} else if s[i] == "B" && s[i+1] == "Y" { // Paper & Draw
			me += draw + paper
		} else if s[i] == "B" && s[i+1] == "X" { // Paper & Lose
			me += rock
		} else if s[i] == "C" && s[i+1] == "X" { // Scissors & Lose
			me += paper
		} else if s[i] == "C" && s[i+1] == "Z" { // Scissors & Win
			me += win + rock
		} else if s[i] == "C" && s[i+1] == "Y" { // Scissors % Draw
			me += draw + scissors
		}
	}

	return me
}

func main() {
	s1, err := fileToSlice("input")
	if err != nil {
		fmt.Println(err)
	}

	total := rockPaperScissors(s1)
	total2 := rockPaperScissors2(s1)
	fmt.Println(total)
	fmt.Println(total2)
}
