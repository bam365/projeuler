/* p25.c - Project Euler problem 25
 * Blake Mitchell, 2012
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "eutil.h"

#define DIGCOUNT 1000

main()
{
        char *a, *b, *tmp;
        int term;
        int max = DIGCOUNT+1;

        a = (char*)malloc(max);
        b = (char*)malloc(max);
        tmp = (char*)malloc(max);
        
        inttostr(0, a, max);
        inttostr(1, b, max);

        for (term = 0; a[DIGCOUNT-1] == '0' || a[DIGCOUNT-1] == '\0'; term++) {
                memcpy(tmp, b, max);
                addstr_inplace(a, b, max);
                memcpy(a, tmp, max);
        }
        printf("The first Fibonacci number with %d digits is:\n\n", DIGCOUNT);
        strnum_reverse(a, max);
        printf("%s\n", a);
        printf("\nThis is term %d in the sequence\n", term);
        
        free(a);
        free(b);
        free(tmp);
}
