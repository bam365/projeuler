package main

import (
        "fmt"
)


type Coins struct {
        Onepound int
        Fiftyp int
        Twentyp int
        Tenp int
        Fivep int
        Twop int
        Onep int
}

        

func main() {
        fmt.Println("This takes several seconds...")
        //Add 8 for the homogeneous coin combos
        numc := Numofcombos() + 8
        fmt.Printf("The number of different ways to make 2 British pounds " +
                   "from coins is %d\n", numc)
}


func (c *Coins) Value() int {
        return c.Onepound*100 + c.Fiftyp*50 + c.Twentyp*20 + c.Tenp*10 +
               c.Fivep*5 + c.Twop*2 + c.Onep
}


func Numofcombos() int {
        count := 0;
        coins := new(Coins);
        IterateOnepound(coins, &count)
        return count
}

//Loop counters for the iterate functions, global so they aren't getting
//constantly GC'ed
var I1LB, I50P, I20P, I10P, I5P, I2P, I1P int


func IterateOnepound(coins *Coins, count *int) {
        for I1LB = 0; I1LB < 2; I1LB ++ {
                coins.Onepound = I1LB
                IterateFiftyp(coins, count)
        }
}

func IterateFiftyp(coins *Coins, count *int) {
        for I50P = 0; I50P < 4; I50P ++ {
                coins.Fiftyp = I50P
                IterateTwentyp(coins, count)
        }
}

func IterateTwentyp(coins *Coins, count *int) {
        for I20P = 0; I20P < 10; I20P ++ {
                coins.Twentyp = I20P
                IterateTenp(coins, count)
        }
}

func IterateTenp(coins *Coins, count *int) {
        for I10P = 0; I10P < 20; I10P ++ {
                coins.Tenp = I10P
                IterateFivep(coins, count)
        }
}

func IterateFivep(coins *Coins, count *int) {
        for I5P = 0; I5P < 40; I5P ++ {
                coins.Fivep = I5P
                IterateTwop(coins, count)
        }
}

func IterateTwop(coins *Coins, count *int) {
        for I2P = 0; I2P < 100; I2P ++ {
                coins.Twop = I2P
                IteratePenny(coins, count)
        }
}

func IteratePenny(coins *Coins, count *int) {
        for I1P = 0; I1P < 200; I1P ++ {
                if coins.Onep = I1P; coins.Value() == 200 {
                        (*count) ++
                        return
                }
        }
}
