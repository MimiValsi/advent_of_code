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

func sliceToLine(s []string) [][]string {
	t1 := []string{}
	for i := 0; i < 8; i++ {
		for j := 0; j < len(s[i]); j++ {
			t1 = append(t1, string(s[i][j]))

		}
	}

	t2 := []string{}
	t3 := [][]string{}
	for i := len(t1) - 2; i > len(t1)-(9*4); i -= 4 {
		for j := i; j > 0; j -= 35 {
			if t1[j] >= "A" && t1[j] <= "Z" {
				t2 = append(t2, t1[j])
			}
		}
		t3 = append(t3, t2)
		t2 = nil
	}

	// Reverse t3
	for i, j := 0, len(t3)-1; i < j; i, j = i+1, j-1 {
		t3[i], t3[j] = t3[j], t3[i]
	}

	return t3

}

func moveFromTo(s []string) []int {

	s1 := []string{}
	// Start i := 10 to ignore what is before
	for i := 10; i < len(s); i++ {
		// fmt.Printf("s1[%d] > %s\n", i, s[i])
		temp := strings.Split(s[i], " ")
		for j := 0; j < len(temp); j++ {
			if temp[j] >= "0" && temp[j] <= "9" {
				s1 = append(s1, temp[j])
			}
		}
	}

	ds := []int{}
	for i := range s1 {
		t, _ := strconv.Atoi(s1[i])
		ds = append(ds, t)
	}

	return ds
}

func trimSlice1(s []int, ds [][]string) {
	for i := 0; i < len(s); i += 3 {
		// MOVE: The number of crates to move
		MOVE := s[i]
		// As all loops start from 0
		// if Origin = 5 then in loop it will start @ 4
		// FROM: Origin
		FROM := s[i+1] - 1
		TO := s[i+2] - 1

		// To append from a cargo to another
		// 1st we copy MOVE crates from Origin to tmpCp
		// 2nd we copy what's left to tmpCp2
		tmpCp := []string{}
		tmpCp2 := []string{}

		// copy crates we need to cmpCp from top to bottom
		for j := len(ds[FROM]) - 1; j >= len(ds[FROM])-MOVE; j-- {
			tmpCp = append(tmpCp, ds[FROM][j])

		}
		// copy what's left
		for o := 0; o < len(ds[FROM])-MOVE; o++ {
			tmpCp2 = append(tmpCp2, ds[FROM][o])
		}

		// Once copy is done, we clear ds[]
		// and append tmpCp2
		ds[FROM] = nil
		ds[FROM] = append(ds[FROM], tmpCp2...)

		// Here we append from Origin copy to Destination
		ds[TO] = append(ds[TO], tmpCp...)

		tmpCp, tmpCp2 = nil, nil
	}

	// Print last crates from each cargo
	for i := 0; i < len(ds); i++ {
		for j := len(ds[i]) - 1; j > len(ds[i])-2; j-- {
			fmt.Print(ds[i][j])
		}
	}
	fmt.Println()
}

func trimSlice2(s []int, ds [][]string) {
	for i := 0; i < len(s); i += 3 {
		// fmt.Println("i >", i)
		// MOVE: The number of crates to move
		MOVE := s[i]
		// As all loops start from 0
		// if Origin = 5 then in loop it will start @ 4
		// FROM: Origin
		FROM := s[i+1] - 1
		// to: Destination
		TO := s[i+2] - 1

		// copy crates we need to cmpCp
		tmpCp, tmpCp2 := []string{}, []string{}
		tmpCp, tmpCp2 = nil, nil

		// copy stack of crates
		for j := len(ds[FROM]) - MOVE; j < len(ds[FROM]); j++ {
			tmpCp = append(tmpCp, ds[FROM][j])

		}
		// copy what's left
		for o := 0; o < len(ds[FROM])-MOVE; o++ {
			tmpCp2 = append(tmpCp2, ds[FROM][o])
		}

		// Once copy is done, we clear ds[]
		// and append tmpCp2
		ds[FROM] = nil
		ds[FROM] = append(ds[FROM], tmpCp2...)

		// Here we append from Origin copy to Destination
		ds[TO] = append(ds[TO], tmpCp...)

		// Clear both slices
		tmpCp, tmpCp2 = nil, nil

	}

	// Print last crates from each cargo
	for i := 0; i < len(ds); i++ {
		for j := len(ds[i]) - 1; j > len(ds[i])-2; j-- {
			fmt.Print(ds[i][j])
		}
	}
	fmt.Println()
}

func main() {
	file, err := fileToSlice("input")
	if err != nil {
		fmt.Println(err)
	}

	// Create Cargo 2D-slice
	stl := sliceToLine(file)
	stl2 := sliceToLine(file)
	// fmt.Println("ds @ main func", ds)

	// Create slice that M-F-T
	mft := moveFromTo(file)

	// Swap crate by crate
	trimSlice1(mft, stl)

	// Swap stack of crates
	trimSlice2(mft, stl2)
}
