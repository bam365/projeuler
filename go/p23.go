// p23.go - Project Euler problem 23
// Blake Mitchell, 2012

package main

import (
        "fmt"
)

const MAX = 28123


type AbundantList []byte

func AbundantList_New(max int) AbundantList {
        alist := make([]byte, max/8 + 1)
        for i := 0; i < len(alist); i++ { alist[i] = byte(0) }
        for n := 1; n <= max; n++ {
                if Divisorsum(n) > n {
                        alist[n/8] |= (1 << uint(n%8))
                }
        }
        return alist
}

func (alist *AbundantList) Find(n int) bool {
        if ((*alist)[n/8] & (1 << uint(n%8))) > byte(0) {
                return true
        }
        return false
}


func main() {

        numbers := make([]int, 0)
        alist := AbundantList_New(MAX)
        for n := 0; n <= MAX; n++ {
                if !Isabundantsum(n, &alist) {
                        numbers = append(numbers, n)
                }
        }
        fmt.Printf("The sum of all numbers that aren't a sum to two " +
                   "abundant numbers is %d\n", Sumarry(numbers))
}



func Divisorsum(num int) int {
        max, sum := num, 1
        for i := 2; i < max; i++ {
                if num % i == 0 {
                        max = num/i
                        sum += i
                        if max != i {
                                sum += max
                        }
                }
        }
        return sum
}

                

func Isabundantsum(num int, alist *AbundantList) bool {
        var j int
        found := false
        max := num/2 
        for i := 1; i <= max && !found; i++ {
                j = num-i
                if alist.Find(i) && alist.Find(j) {
                        found = true
                }
        }
        return found
}


func Sumarry(arry []int) int {
        sum := 0
        for _, n := range(arry) {
                sum += n
        }
        return sum
}



