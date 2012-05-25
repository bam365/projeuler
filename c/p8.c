/* p8.c - Project Euler problem 8 - Find largest sum of consecutive digits
 *        in a 1000-digit number
 * Blake Mitchell, 2011
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 4096 
#define SECSIZE 5
#define DIGTONUM(x) ((int)(x - '0'))


int read_number(FILE *f, char *buf, int maxsize);


main() 
{
        char *number;
        int maxprod;
        
        number = (char*)malloc(MAX_INPUT_SIZE);
        memset(number, '\0', MAX_INPUT_SIZE);

        read_number(stdin, number, MAX_INPUT_SIZE);
        maxprod = max_digit_prod(number, strlen(number), SECSIZE);
        printf("The maximum product of %d digits in the 1000-digit number "
               " is %d\n", SECSIZE, maxprod);
}
        



int read_number(FILE *f, char *buf, int maxsize)
{       
        char c;
        int size;

        for (size = 0; (c = fgetc(f)) != EOF && size < (maxsize-1); size++) 
                buf[size] = c;
        buf[size] = '\0';

        return size;
}
                

int max_digit_prod(char *buf, int size, int secsize) 
{
        int i, prod, maxprod = 1;
        char *d;

        for (d = buf; (d - buf) < (size - secsize); d++) {
                for (i = 0, prod = 1; i < secsize; i++)
                        prod *= DIGTONUM(d[i]);
                if (prod > maxprod)
                        maxprod = prod;
        }

        return maxprod;
}




