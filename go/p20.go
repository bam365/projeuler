package main

import (
        "fmt"
        "./eutil/eutil"
)


func main() {
        dsum := eutil.Digitsum(eutil.Factorial(100))
        fmt.Printf("The sum of the digits in 100! is %d\n", dsum)
}

