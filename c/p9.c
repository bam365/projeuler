/* p9.c - Project Euler problem 9, Find the first Pythongorean triplet where
 *        a+b+c=1000
 * Blake Mitchell, 2012
 */

#include <stdio.h>

#define SUM 1000
#define MAX 1000

main()
{
        int a, b, c;
        int found = 0;
        
        /* Mmmm, brute force */
        for (a = 1; a <= MAX && !found; a++) {
                for (b = a; b <= MAX && !found; b++) {
                        for (c = b; c <= MAX && !found; c++) {
                                if (a + b + c == SUM && a*a + b*b == c*c)
                                        found = 1;
                        }
                }
        }

        printf("A pythagorean triplet where a+b+c=1000: \n");
        printf("a = %d, b = %d, c = %d\n", a, b, c);
}
