package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type node struct {
        name string
        size int
        isFile bool
        child map[string]*node
        parent *node
}

func main() {
        f, err := os.Open("input")
        if err != nil {
                fmt.Println("File does not exist")
                os.Exit(1)
        }
        defer f.Close()

        fs := bufio.NewScanner(f)
        var currentDir *node
        
        dirs := []*node{}

        for fs.Scan() {
                line := strings.Fields(fs.Text())
                if len(line) > 2 {
                        if line[2] == ".." {
                                currentDir = currentDir.parent
                        } else if line[2] == "/" {
                                currentDir = &node{"/", 0, false, 
                                        make(map[string]*node), nil} 
                                dirs = append(dirs, currentDir)
                        } else {
                                currentDir = currentDir.child[line[2]]
                        }
                } else if line[0] == "dir" {
                        currentDir.child[line[1]] = &node{line[1], 0, false, 
                        make(map[string]*node), currentDir}
                        dirs = append(dirs, currentDir.child[line[1]])
                } else if line[0] != "$" {
                        size, _ := strconv.Atoi(line[0])
                        currentDir.child[line[1]] = &node{line[1], size, true, 
                        nil, currentDir}
                }
        }

        free := 30_000_000 - (70_000_000 - calcSize(*dirs[0]))
        smallestDir := calcSize(*dirs[0])

        for _, dir := range dirs {
                size := calcSize(*dir)
                
                if size > free && size - free < smallestDir - free {
                        smallestDir = size
                }
        }

        fmt.Println(smallestDir)

        // var totalSize int
        // for _, dir := range dirs {
        //         size := calcSize(*dir)
        //         if size <= 100_000 {
        //                 totalSize += size
        //         }
        // }

        // fmt.Println(totalSize)
}

func calcSize(root node) (size int) {
        if root.isFile {
                return root.size
        }

        for _, d := range root.child {
                size += calcSize(*d)
        }

        return
}
