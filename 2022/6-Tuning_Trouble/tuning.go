package main

import (
	"bufio"
	"fmt"
	"os"
)
// Read each row in file and append it to a []string{}
func fileToSlice(s string) ([]string, error) {
	file, err := os.Open(s)
	if err != nil {
		return nil, err
	}

	str1 := []string{}
	fs := bufio.NewScanner(file)
	fs.Split(bufio.ScanLines)

	for fs.Scan() {
		line := fs.Text()
		str1 = append(str1, line)
	}
	return str1, nil

}

// Read []string{} with multiple "rows" and transform it into
// a single character
func sliceToString(s []string) []string {
	ds := []string{}
	for i := 0; i < len(s); i++ {
		for j := 0; j < len(s[i]); j++ {
			ds = append(ds, string(s[i][j]))
		}
	}

	return ds
}

// Count each unique char for the first 3 rows inside []string{}
// and the 4th is str
// 1st part
func contains(s []string, str string) bool {
	// sum1, sum2, sum3 := 0, 0, 0
	ls := 0
	sum := []int{0, 0, 0}
	for i := 0; i < len(s); i++ {

		// fmt.Println(s[i])
		for j := 0; j < len(s); j++ {

			if s[i] == s[j] {
				sum[i]++
			}
		}
		if str == s[i] {
			ls++
		}

	}

	for i := 0; i < len(sum); i++ {
		if sum[i] > 1 || ls > 0 {
			return false
		}
	}

	return true
}

// 2nd part
func containsBis(s []string, str string) bool {
	ls := 0
	sum := []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	for i := 0; i < len(s); i++ {
		for j := 0; j < len(s); j++ {
			if s[i] == s[j] {
				sum[i]++
			}
		}
		if str == s[i] {
			ls++
		}
	}

	for i := 0; i < len(sum); i++ {
		if sum[i] > 1 || ls > 0 {
			return false
		}
	}

	return true
}

func radar(s []string) {
	tmp, tmp2 := []string{}, []string{}


	t := 4
	tt := 14

	for i := 0; i < 1; i++ {
		for j := 0; j < len(s)-2; j++ {
			tmp = append(tmp, s[j], s[j+1], s[j+2])
			// fmt.Println("s[j] >", s[j])
			ret := contains(tmp, s[j+3])
			if ret {
				break
			}
			t++
			tmp = nil
		}
	}

	for i := 0; i < 1; i++ {
		for j := 0; j < len(s)-12; j++ {
			tmp2 = append(tmp2, s[j], s[j+1], s[j+2], s[j+3],
				s[j+4], s[j+5], s[j+6], s[j+7], s[j+8],
				s[j+9], s[j+10], s[j+11], s[j+12])
			ret2 := containsBis(tmp2, s[j+13])
			if ret2 {
				break
			}
			tt++
			tmp2 = nil
		}
	}

	fmt.Println(t)
	fmt.Println(tt)

}

func main() {
	file , err := fileToSlice("input")
	if err != nil {
		fmt.Println(err)
	}

	ret := sliceToString(file)

	radar(ret)

}
