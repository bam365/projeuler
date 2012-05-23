// p25.go - Project Euler problem 25
// Blake Mitchell, 2012

package main


import (
        "fmt"
        "math/big"
)


func main() {
        bfib := BigFibonacci()
        term, n := bfib()
        for ; len(n.String()) < 1000; term, n = bfib() { }
        fmt.Println("The first Fibonacci number with 1000 digits is:\n")
        fmt.Println(n)
        fmt.Printf("\nThis is term %d in the sequence.\n", term)
}


func BigFibonacci() func() (int, *big.Int) {
        a := big.NewInt(int64(0))
        b := big.NewInt(int64(1))
        tmp := big.NewInt(0)
        term := 0
        return func() (int, *big.Int) {
                tmp.Add(b, big.NewInt(int64(0)))
                b.Add(a, b)
                a.Add(tmp, big.NewInt(int64(0)))
                term++
                return term, a
        }
}


