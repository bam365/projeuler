/* maxtrisum.c - Find the maximum sum from the top of a given triangle to the
 *               base, used for Project Euler problems 18 and 67
 * Blake Mitchell, 2011
 */

#include <stdio.h>
#include <stdlib.h>


int triangle_size(int nrows);
int triangle_row(int n);
void child_indices(int n, int *left, int *right);
int read_triangle(FILE *stream, int *tree);
int triangle_longest_path(int *tri, int tsize);


int main()
{
        int n, left, right, tsize, i;
        int *tri;

        tri = (int*)malloc(sizeof(int));

        if ((tsize = read_triangle(stdin, tri)) < 1) 
                printf("Bad triangle\n");
        else
                printf("Greatest path through triangle: %d\n",
                        triangle_longest_path(tri, tsize));

        free(tri);

        return 0;
}



int triangle_size(int nrows)
{
        int i, size;

        size = 0;
        for (i = nrows; i > 0; i--) 
                size += i;
        return size;
}


int triangle_row(int n) 
{
        int row;
        
        //Is there a non-iterative way to do this? 
        for (row = 1; n >= triangle_size(row); row++);
        return row;
}


void child_indices(int n, int *left, int *right) 
{
        int row, rowoff;

        row = triangle_row(n);
        rowoff = n - triangle_size(row-1);
        *left = triangle_size(row) + rowoff;
        *right = *left + 1;
}


int read_triangle(FILE *stream, int *tree) 
{
        int ncount, rcount, tsize, n;
        
        ncount = 0;
        rcount = 0;
        tsize = triangle_size(rcount);
        while (fscanf(stream, "%d", &n) == 1) {
                if ((++ncount) > tsize) {
                        rcount ++;
                        tsize = triangle_size(rcount);
                        tree = (int*)realloc(tree, sizeof(int) * tsize);
                }
                tree[ncount-1] = n;
        }
        if (ncount == 0 || ncount != tsize) 
                return -1;
        else 
                return ncount;
        
}


void lengths_set_vertex(int *tri, int *lengths, int tsize, int p, int q) 
{
        int l;

        if (q < tsize) {
                l = lengths[p] + tri[q];
                if (lengths[q] < l) 
                        lengths[q] = l;
        }
}


/* Finds the max in the bottom-row vertices for lengths array */
int lengths_max(int *lengths, int lsize) 
{
        int row, max, i;
        
        max = 0;
        row = triangle_row(lsize-1);
        for (i = triangle_size(row-1); i < lsize; i++) {
                if (lengths[i] > max)
                        max = lengths[i];
        }

        return max;
}



int triangle_longest_path(int *tri, int tsize) 
{
        int *lengths, left, right, max;
        int i, j;

        lengths = (int*)calloc(sizeof(int), tsize);
        for (i = 0; i < tsize; i++)
                lengths[i] = tri[i];

        for (i = 0; i < tsize; i++) {
                child_indices(i, &left, &right);
                lengths_set_vertex(tri, lengths, tsize, i, left);
                lengths_set_vertex(tri, lengths, tsize, i, right);
        }

        max = lengths_max(lengths, tsize);
        free(lengths);
        
        return max;
}
       



