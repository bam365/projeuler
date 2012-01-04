/* p8.c - Project Euler problem 8 - Find largest sum of consecutive digits
 *        in a 1000-digit number
 * Blake Mitchell, 2011
 */

#include <stdio.h>


#define MAX_INPUT_SIZE 4096 


int read_number(FILE *f, char *buf, int maxsize);





int read_number(FILE *f, char *buf, int maxsize)
{       
        char c;
        int size;

        for (size = 0; (c = fgetc(f)) != EOF && size < (maxsize-1); size++) 
                buf[size] = c;
        buf[size] = '\0';

        return size;
}
                

int max_digit_sum(char *buf

