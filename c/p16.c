/* p16.c - Project Euler problem 16 
 *         Find the sum of the digits in 2^1000 
 * Blake Mitchell, 2011
 */

#include <stdio.h>
#include "eutil.h"

/*1000 digits seems like enough to hold 2^1000*/
#define MAX_DIGITS      1000




int main()
{
        char result[MAX_DIGITS];
        int base, power;

        base = 2;
        power = 1000;
        powstr(base, power, result, MAX_DIGITS);
        printf("Sum of digits in %d^%d = %d\n", base, power, 
                             digitsum(result,  MAX_DIGITS)); 
        return 0;
}




