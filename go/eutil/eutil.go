package eutil

import (
        "strconv"
        //"math"
)


func Isprime (n uint) bool {
        if n < 2 {
                return false;
        } else if n == 2 {
                return true;
        }
        for i := uint(2); i <= n / i; i++ {
                if float32(n/i) == float32(n)/float32(i) {
                        return false
                }
        }
        return true
}


func Primes() func() uint {
        var n uint = 2
        return func() uint {
                for n += 1; !Isprime(n); n++ {}
                return n
        }
}
                

func Max(a, b int, nums ...int) int {
        var max int
        if a > b {
                max = a
        } else {
                max = b
        }
        for _, n := range nums {
                if n > max {
                        max = n
                }
        }
        return max
}


func Strtodig(d byte) int {
        return int(d - '0')
} 


func Digtostr(d int) string {
        ret := byte(d % 10)
        return string(ret + '0')        
}


func Reversenum(n string) string {
        newn := ""
        for i := len(n) - 1; i >= 0; i-- {
                newn += string(n[i])
        }
        return newn
}


func Add(a, b string) string {
        newa, newb := Reversenum(a), Reversenum(b)
        sum := ""
        var d, dsum int
        carry := 0
        for i := 0; i < Max(len(newa), len(newb)); i++ {
                dsum = carry
                if i < len(newa) {
                        dsum += Strtodig(newa[i])
                }
                if i < len(newb) {
                        dsum += Strtodig(newb[i])
                }
                d, carry = dsum % 10, dsum / 10
                sum += Digtostr(d)
        }
        if carry > 0 {
                sum += Digtostr(carry)
        }
        return Reversenum(sum)
}


func Multdig(n, dig string) string {
        dprod, carry, tmp := 0, 0, 0
        ret := ""
        d := Strtodig(dig[0])
        for i := len(n) - 1; i >= 0; i-- {
                dprod = d * Strtodig(n[i]) + carry
                tmp, carry = dprod % 10, dprod / 10
                ret = Digtostr(tmp) + ret
        }
        if carry > 0 {
                ret = Digtostr(carry) + ret
        }
        return ret
}


func Mult(a, b string) string {
        prod, lprod := "0", "0"
        for i := len(a) - 1; i >= 0; i-- {
                lprod = Multdig(b, string(a[i]))
                for j := i; j < len(a)-1; j++ {
                        lprod =  lprod + "0"
                }
                prod = Add(prod, lprod)
        }
        return prod
}


func Factorial(n int) string {
        prod := "1"
        for i := 2; i <= n; i++ {
                prod = Mult(strconv.Itoa(i), prod)
        }
        return prod
}


func Digitsum(d string) int {
        sum := 0
        for i := 0; i < len(d); i++ {
                sum += int(Strtodig(d[i]))
        }
        return sum
}
