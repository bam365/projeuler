// gridprod.go - Find the maximum product of 4 adjacent values in a 20x20 grid
//               Used for Project Euler problem 11
// Blake Mitchell, 2011

package main

import (
        "fmt"
        "bufio"
        "os"
        "strings"
        "strconv"
)


//Note: Multiplying these direction constants by PI/4 should give you the angle
//in radians
const (
        DIR_EAST = iota
        DIR_NORTHEAST
        DIR_NORTH
        DIR_NORTHWEST
        DIR_WEST
        DIR_SOUTHWEST
        DIR_SOUTH
        DIR_SOUTHEAST
)


type Grid [][]int



func main() {
        if g, err := ReadGrid(bufio.NewReader(os.Stdin)); err != nil {
                fmt.Println("Error reading grid: " + err.String()) 
        } else if g == nil {
                fmt.Println("Error: Mal-formed grid")
        } else {
                fmt.Printf("The maximum product of four adjacent values" +
                           " is %d\n", g.MaxNprod(4))
        }
}



func DirSincos(dir int) (int, int) {
        var sin, cos int
        switch dir {
                case DIR_EAST: sin, cos = 1, 0
                case DIR_NORTHEAST: sin, cos = 1, 1
                case DIR_NORTH: sin, cos = 0, 1
                case DIR_NORTHWEST: sin, cos = -1, 1
                case DIR_WEST: sin, cos = -1, 0
                case DIR_SOUTHWEST: sin, cos = -1, -1
                case DIR_SOUTH: sin, cos = 0, -1
                case DIR_SOUTHEAST: sin, cos = 1, -1
        }
        return sin, cos
}


func grid_read_row(s *bufio.Reader) ([]int, os.Error) {
        var linebuf string
        ret := make([]int, 0)
        linebuf, rerr := s.ReadString('\n')
        if rerr != nil {
                return nil, rerr
        }
        for _, s := range(strings.Fields(linebuf)) {
                n, perr := strconv.Atoi(s)
                if perr != nil {
                        return nil, perr
                }
                ret = append(ret, n)
        }
        return ret, nil
}


func ReadGrid(s *bufio.Reader) (*Grid, os.Error) {
        firstrow, err := grid_read_row(s)
        if err != nil {
                return nil, err
        }
        var g Grid = make([][]int, len(firstrow))
        g[0] = firstrow 
        for i := 1; i < len(g); i++ {
                row, rerr := grid_read_row(s)
                if rerr != nil {
                        return nil, rerr
                } else if len(row) != len(g) {
                        return nil, nil 
                }
                g[i] = row;
        }
        return &g, nil
}


func (g Grid) Dim() int {
        return len(g)
}


func (g Grid) RowCol(r, c int) int {
        var ret int
        if (r >= 0 && r < g.Dim() && c >=0 && c < g.Dim()) {
                ret = g[r][c]
        } else {
                ret =  0
        }
        return ret
}


func (g Grid) Nprod(r, c, dir, n int) int {
        dx, dy := DirSincos(dir)
        prod := 1
        for i := 0; i < n; i++ {
                prod *= g.RowCol(r, c)
                r, c = r+dy, c+dx
        }
        return prod
}
                

func (g Grid) MaxNprod(n int) int {
        maxprod, p := 0, 0
        for r := 0; r < g.Dim(); r++ {
        for c := 0; c < g.Dim(); c++ {
                for dir := DIR_EAST; dir <= DIR_SOUTHEAST; dir++ {
                        if p = g.Nprod(r, c, dir, n); p > maxprod {
                                maxprod = p
                        }
                }
        }}
        return maxprod
}
