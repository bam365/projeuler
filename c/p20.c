/* p20.c - Project Euler problem 20
 *         Find the sum of the digits in 100!
 * Blake Mitchell, 2011
 */

#include <stdio.h>
#include "eutil.h"


/*1000 digits seems like enough to hold 100!*/
#define MAX_DIGITS      1000



int main()
{
        char result[MAX_DIGITS];
        int fac = 100;

        factorial(fac, result, MAX_DIGITS);
        printf("Sum of digits in %d! = %d\n", fac, 
                        digitsum(result,  MAX_DIGITS)); 
        return 0;
}


