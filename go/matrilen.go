// maxtrilen.go - Finds maximum sum from the top of a triangle to the base,
//                used for Project Euler 
// Blake Mitchell, 2011

package main


import (
        "fmt"
)


type Triangle []int
type Lengths  []int



func main() {
        var n int
        
        fmt.Scanf("%d", &n)
        fmt.Printf("%d %d\n", Trisize(n), Getrow(n))
}


func Trisize(rows int) int {
        sum := 0
        for r := rows; r > 0; r-- {
                sum += r
        }

        return sum
}


func Getrow(n int) int {
        var row int
        for row = 1; n >= Trisize(row); row++ {}
        return row
}


func (Triangle *t) Read(s io.Reader) {
        var n int;
        ncount, rcount := 0, 0

        t = make([]int, 1, 0)
        for n = 



