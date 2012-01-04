package main

import "fmt"
import "math"



func main() {
        words := []string{"zero", "one", "two", "three", "four", "five", "six",
                        "seven", "eight", "nine"}
        teens := []string {"ten", "eleven", "twelve", "thirteen", "fourteen",
                           "fifteen", "sixteen", "seventeen", "eighteen",
                           "nineteen"}
        tens := []string{"zero", "ten", "twenty", "thirty", "forty", "fifty",
                         "sixty", "seventy", "eighty", "ninety"}

        var numstr string
        total := 0
        for i := uint16(1); i <= 1000; i++ {
                numstr = num2word(i, words, tens, teens, "hundred", "thousand")
                total += len(numstr)
        }
        fmt.Printf("The number of letters needed " +
                   "to say the numbers 1-1000 is %d\n", total);
}


func get_ith_digit(n uint, i uint) uint {
        ret := (n / uint((math.Pow10(int(i))))) % 10
        return  ret
}


func num2word(n uint16, words []string, tens []string, teens []string,
              hundred, thousand string) string {
        ret := ""
        isteen := false
        if thous := get_ith_digit(uint(n), 3); thous != 0 {
                ret = words[thous] + thousand
        }
        if hund := get_ith_digit(uint(n), 2); hund != 0 {
                ret += words[hund] + hundred
        }
        //This is stupid, but apparently British people do this
        if ((n >= 100) && (n % 100 != 0)) {
                ret += "and"
        }
        if ten := get_ith_digit(uint(n), 1); ten != 0 {
                if isteen = ten == 1; !isteen {
                        ret += tens[ten]
                }
        }
        if ze := get_ith_digit(uint(n), 0);
           ze != 0 || isteen || ret == "" {
                if isteen {
                        ret += teens[ze]
                } else {
                        ret += words[ze]
                }
        }
        return ret
}
