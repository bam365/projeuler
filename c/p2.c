/* p2.c - Project Euler problem 2
 *        By considering the terms in the FIbonacci sequence whose values do
 *        not exceed four million, find the som of the even-valued terms
 * Blake Mitchell, 2011
 */


#include <stdio.h>
#include <stdlib.h>
#include "eutil.h"

#define MAX_DIGITS              100



int fib_even_sum(unsigned long n, char *sum, int max);


int main()                              
{
        char sum[MAX_DIGITS];
        unsigned long max_fib = 4000000;
         
        fib_even_sum(max_fib, sum, MAX_DIGITS); 
        strnum_reverse(sum, MAX_DIGITS);
        printf("The sum of all even terms in Fibonacci up to %d is %s\n",
                        max_fib, sum);
        
        return 0;
}
          




int fib_even_sum(unsigned long n, char *sum, int max)
{
        unsigned long a, b, tmp;
        char *nbuf;

        a = 1;
        b = 2;
        nbuf = (char*)malloc(sizeof(char)*max);
        inttostr(0, sum, max);
        while (b <= n) {
                if (!(b & 1)) {
                        inttostr(b, nbuf, max);
                        addstr_inplace(nbuf, sum, max);
                }
                tmp = a;
                a = b;
                b += tmp;
        }

        free(nbuf);
        return 0;
}
