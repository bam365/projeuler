package main

import (
        "fmt"
        "strconv"
        "./eutil/eutil"
)


func main() {
        dsum := eutil.Digitsum(pow(2, 1000))
        fmt.Printf("The sum of the digits in 100! is %d\n", dsum)
}


func pow(b, n int) string {
        bs := strconv.Itoa(b) 
        prod := bs
        for i := 1; i < n; i++ {
                prod = eutil.Multdig(prod, bs)
        }
        return prod
}
