package main

import (
        "fmt"
        "strconv"
)

func main() {
        var pow uint = 5
        nlist := make([]uint, 0)
        maxnum := MaxNumber(pow)

        for n := pow; n <= maxnum; n++ {
                if (n == DigitPowSum(n, pow)) {
                        nlist = append(nlist, n)
                }
        }

        fmt.Printf("The sum of all numbers for which the sum of their digits" +
                   " to the %d power = the number itself\n is %d\n",
                   pow, Sumnumbers(nlist))
}


func Digtonum(dig uint8)  uint {
        return uint(dig - '0')
}


func Ipow(n uint, p uint) uint {
        var ret uint = 1

        for d := uint(0); d < p; d++ {
                ret *= n;
        }

        return ret;
}


func MaxNumber(pow uint) uint {
        maxdig := Ipow(9, pow)
        var dig, ret uint

        for dig = 2; Ipow(10, dig) < dig*maxdig; dig++ {
        } 
        ret = dig*maxdig

        return ret
}


func DigitPowSum(n uint, p uint) uint {
        nstr := strconv.FormatUint(uint64(n), 10)
        var sum uint = 0;

        for i := 0; i < len(nstr); i++ {
                sum += Ipow(Digtonum(nstr[i]), p)
        }

        return (sum)
}


func Sumnumbers(nlist []uint) uint {
        var sum uint = 0

        for _, s := range(nlist) {
                sum += s
        }

        return sum
}
