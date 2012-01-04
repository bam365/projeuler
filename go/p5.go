package main

import "fmt"


type Plist map[int]int


func main() {
        fmt.Println(lcm_range(20))
}


func isprime(n int) bool {
        if n < 2 {
                return false
        }
        if n == 2 {
                return true
        }
        for i := 2; i <= n / i; i++ {
                if  n % i == 0 {
                        return false
                }
        }
        return true
}


func (pl *Plist) hit_greater(p, c int) {
        if c > (*pl)[p]  {
                (*pl)[p] = c
        }
}


func product(pl Plist) int {
        if len(pl) == 0 {
                return 0
        }
        prod := 1;
        for p, c := range pl {
                for i := 0; i < c; i++ {
                        prod *= p
                }
        }
        return prod
}


func (pl *Plist) primefac(n int) {
        if isprime(n) {
                (*pl)[n] = 1
                return
        }
        for i := 2; i <= n; i++ {
                if  isprime(i) && n % i == 0 {
                        (*pl)[i] = (*pl)[i] + 1
                        n = n / i
                        i = 1
                }
        }
}


func lcm_range(n int) int {
        lcmpl := make(Plist)
        for i := 2; i <= n; i++ {
                pl := make(Plist)
                pl.primefac(i)
                for p, c := range pl {
                        lcmpl.hit_greater(p, c)
                }
        }
        return product(lcmpl)
}
