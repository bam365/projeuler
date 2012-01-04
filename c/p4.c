/* p4.c - Project Euler problem 4
 *        Find the largest palindrome made from the product of two 3-digit
 *        numbers
 * Blake Mitchell, 2011
 */

#include <stdio.h>
#include "eutil.h"


#define MAX_DIGITS              7



int is_palindrome(unsigned int n);
int max_palindrome(int max);


int main()
{
        int max;
        
        max = 999;
        printf("The max palindrome of two 3-digit products is %d\n",
                        max_palindrome(max));
        
        return 0;
}



int is_palindrome(unsigned int n)
{
        static char PLNDRM_BUF1[MAX_DIGITS];
        static char PLNDRM_BUF2[MAX_DIGITS];

        inttostr(n, PLNDRM_BUF1, MAX_DIGITS);
        inttostr(n, PLNDRM_BUF2, MAX_DIGITS);
        strnum_reverse(PLNDRM_BUF2, MAX_DIGITS);
        /* I think strncmp might be slow, might make a replacement function to
         * see if it performs better */
        if (!strncmp(PLNDRM_BUF1, PLNDRM_BUF2, MAX_DIGITS))
                return 1;
        else
                return 0;
}


int max_palindrome(int max)
{
        int i, j;
        int p, maxp;

        maxp = 0;
        for (i = 1; i <= max; i++)
        for (j = i; j <= max; j++) {
                p = i*j;
                if (p > maxp && is_palindrome(p))
                        maxp = p;
        }
        
        return maxp;
}
