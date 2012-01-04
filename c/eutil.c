/* eutil.c - Utilities for Project Euler problems
 * Blake Mitchell 2011
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "eutil.h"




int inttostr(unsigned long n, char *str, int max)
{
        int i, numdig, dig;

        if (max < 1) 
                return 0;
        if (n == 0) {
                memset(str, '0', 1);
                return 1;
        }

        memset(str, '\0', max);
        numdig = (unsigned long)log10((long double)n) + 1;
        for (i = 0; i < numdig && i < max; i++) {
                dig = (n / (int)pow(10.0, (double)i)) % 10;
                str[i] = TODIGIT(dig);
        }
        
        return i;
}


int addstr_inplace(char *summand, char *sum, int max)
{
        int i, dig, rem;

        rem = 0;
        for (i = 0; i < max; i++) {
                if (!ISDIGIT(sum[i]) && !ISDIGIT(summand[i])) {
                        if (!rem)
                                continue;
                        dig = rem;
                } else if (!ISDIGIT(sum[i])) {
                        dig = FROMDIGIT(summand[i]) + rem;
                } else if (!ISDIGIT(summand[i])) {
                        dig = FROMDIGIT(sum[i]) + rem;
                } else {
                        dig = FROMDIGIT(sum[i]) + FROMDIGIT(summand[i]) + rem;
                }
                sum[i] = TODIGIT(dig % 10);
                rem = dig / 10;
        }

        return i;
}


void shift_left(char *nstr, int n, int max)
{
        int i;

        if (n > max) 
                return;
        for (i = max; i >= 0; i--)
                nstr[i] = (i >= n) ? nstr[i - n] : '0';
}


int multch(char *fac, char n, char *prod, int max)
{
        int i, dig, rem, ndig;

        if (max < 1)
                return -1;
        if (n == '0') {
                prod[0] = '0';
                return 0;
        }

        rem = 0;
        ndig = FROMDIGIT(n);
        for (i = 0; i < max; i++) {
                if (!ISDIGIT(fac[i])) {
                        if (!rem)
                                continue;
                        dig = rem;
                } else {
                        dig = FROMDIGIT(fac[i]) * ndig + rem;
                }
                prod[i] = TODIGIT(dig % 10);
                rem = dig / 10;
        }
        return 0;
}


int multstr(char *fac1, char *fac2, char *prod, int max)
{
        int i, j;
        char *p;

        p = (char*)malloc(sizeof(char)*max);

        for (i = 0; i < max; i++) {
                if (!ISDIGIT(fac2[i]))
                        continue;
                memset(p, '\0', max);
                multch(fac1, fac2[i], p, max);
                shift_left(p, i, max);
                addstr_inplace(p, prod, max);
        }
                      
        free(p);
        return 0;
}


int factorial(unsigned short n, char *fac, int max)
{
        int i;
        char *prod, *tmp;

        prod = (char*)malloc(max);
        tmp = (char*)malloc(max);
        inttostr(1, fac, max);
        for (i = 2; i <= n; i++) {
                memcpy(tmp, fac, max);
                memset(fac, '\0', max);
                inttostr(i, prod, max);
                multstr(tmp, prod, fac, max);
        }

        free(prod);
        free(tmp);
        return 0;
}


int digitsum(char *n, int max)
{
        int i, sum;

        sum = 0;
        for (i = 0; i < max; i++)
                if (ISDIGIT(n[i]))
                        sum += FROMDIGIT(n[i]);
        return sum;
}


void strnum_reverse(char *n, int max)
{
        int i, j;
        char *buf;

        buf = (char*)malloc(sizeof(char)*max);
        memset(buf, '\0', max);
        j = 0;
        for (i = max - 1; i >= 0; i--) {
                if (ISDIGIT(n[i])) 
                        buf[j++] = n[i];
        }
        memcpy(n, buf, max);
        free(buf);
}


int powstr(unsigned short n, unsigned short p, char *pow, int max)
{
        int i;
        char *prod, *tmp;

        prod = (char*)malloc(max);
        tmp = (char*)malloc(max);
        inttostr(1, pow, max);
        for (i = 0; i < p; i++) {
                memcpy(tmp, pow, max);
                memset(pow, '\0', max);
                inttostr(n, prod, max);
                multstr(tmp, prod, pow, max);
        }

        free(prod);
        free(tmp);
        return 0;
}


int isprime(unsigned int n)
{
        unsigned int i;

        if (n <= 1) 
                return 0;
        
        for(i = 2; i <= n / i; i++)
                if ((long double)(n)/i == (long double)(n/i))
                        return 0;
        return 1;
}
