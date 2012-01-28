// sumlines.go - Find the sum of all newline-separated numbers from stdin
// Blake Mitchell, 2012

//File IO in Go is _really_ bad.

package main

import (
        "fmt"
        "bufio"
        "os"
        "./eutil/eutil"
)


func main() {
        nums, err := Readnumbers(bufio.NewReader(os.Stdin)) 
        if err != nil {
                fmt.Println(err.String())
        } else {
                sum := Sumnumbers(nums)
                fmt.Printf("First 10 digits of the sum of %d numbers: %s\n", 
                           len(nums), sum[:10])
        }
        
}


func Readnumbers(in *bufio.Reader) ([]string, os.Error) {
        nums := make([]string, 0) 
        line := "" 
        var ch byte
        var err os.Error
        for ch, err = in.ReadByte(); err == nil; 
            ch, err = in.ReadByte() { //This line is stupid...
                if ch == '\n' || ch == ' ' || ch == '\t' {
                        if line != "" { 
                                nums = append(nums, line)
                                line = ""
                        }
                } else if ch < '0' || ch > '9' {
                        return nil, os.NewError("Bad input")
                } else {
                        line += string(ch)
                }
        }

        if err != os.EOF {
                return nil, err
        }

        return nums, nil
}
                
                
func Sumnumbers(nums []string) string {
        sum := "0"
        for _, n := range(nums) {
                sum = eutil.Add(sum, n)
        }
        
        return sum
}
