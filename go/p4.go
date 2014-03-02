package main

import "fmt"

func NumDigits(n int) int {
        r := 0
        switch {
        case n < 10: r = 1 
        case n < 100: r = 2 
        case n < 1000: r = 3 
        case n < 10000: r = 4 
        case n < 100000: r = 5 
        default: r = 6 
        }
        return r
}


func Pow10(n int) int {
        r := 0
        switch {
        case n == 0: r = 1
        case n == 1: r = 10
        case n == 2: r = 100
        case n == 3: r = 1000
        case n == 4: r = 10000
        case n == 5: r = 100000
        default: r = 1000000
        }
        return r
}


func NthDigit(n, d int) int {
        return (n % Pow10(d+1)) / Pow10(d);
}


func IsPalindrome(n int) bool {
        digcount := NumDigits(n) - 1
        for i, j := 0, digcount; i < j; i, j = i+1, j-1 {
                if NthDigit(n, i) != NthDigit(n, j) {
                        return false
                }
        }
        return true;
}
                        

func main() {
        max := 0
        for i := 100; i <= 999; i++ {
                for j := 100; j <= 999; j++ {
                        prod := i * j
                        if (IsPalindrome(prod) && prod > max) {
                                max = prod
                        }
                }
        }
        fmt.Println(max)
}

        
