//p28.go - Project Euler problem 28
//Blake Mitchell, 2012

package main;

import (
        "fmt"
        "big"
)

const SPIRAL_RADIUS = 501


func main() {
        dsum := big.NewInt(1)
        lc, sl := big.NewInt(0), big.NewInt(0)
        var j int
        for i := int64(2); i <= SPIRAL_RADIUS; i++ {
                lc = spiral_upper_left_corner(i)
                sl.Sub(spiral_side_len(i), big.NewInt(1))
                dsum.Add(dsum, lc)
                for j = 0; j < 3; j++ {
                        lc.Sub(lc, sl)
                        dsum.Add(dsum, lc)
                }
        }
        diam := spiral_side_len(SPIRAL_RADIUS)
        fmt.Printf("Sum of diagonals in %dx%d spiral: ", diam, diam)
        fmt.Println(dsum)
}


func spiral_upper_left_corner(iter int64) *big.Int {
        n := spiral_side_len(iter)
        n.Mul(n, n)
        return n
}


func spiral_side_len(iter int64) *big.Int {
        //The big package is incredibly awkward, so in case you can't tell,
        // side_len = iter*2 - 1
        n := big.NewInt(0)
        n = n.Add(n.Mul(big.NewInt(iter), big.NewInt(2)), big.NewInt(-1))
        return n
}

