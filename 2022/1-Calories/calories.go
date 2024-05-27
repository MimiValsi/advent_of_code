package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func calCount(a []string) (int, []int) {
	sum := 0
	ret := 0
	var retSlice []int
	for i := 0; i < len(a); i++ {
		if len(a[i]) == 0 {
			retSlice = append(retSlice, sum)
			sum = 0
			continue
		}
		b, err := strconv.Atoi(a[i])
		if err != nil {
			return -1, nil
		}

		sum += b

	}
	return ret, retSlice
}

func sortSlice(a []int) int {

	sort.Ints(a)
	fmt.Printf("sortSlice slice > %d\n", a)
	b := len(a)
	return a[b-1] + a[b-2] + a[b-3]
}

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

func main() {
	s1, err := fileToSlice("input")
	if err != nil {
		fmt.Println(err)
	}

	s2, s3 := calCount(s1)
	s4 := sortSlice(s3)
	fmt.Println(s3)
	fmt.Printf("Max cal in elf > %d\n", s2)
	fmt.Printf("Total 3 most calories > %d\n", s4)
}
