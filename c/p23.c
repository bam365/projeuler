/* p23.c - Project Euler problem 23
 * Blake Mitchell, 2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 28123


struct alist_node {
        int n;
        struct alist_node* next;
};


struct Alist {
        char *arry; 
        int asize;
        int max;
};


void alist_add(struct Alist* al, int n) 
{
        if (n > al->max) 
                return;

        al->arry[n/8] |= (1 << (n%8));
} 

struct Alist alist_new(int max) 
{
        struct Alist al;
        
        al.asize = max/8 + 1;
        al.arry = (char*)malloc(al.asize);
        al.max = max;
        memset(al.arry, '\0', al.asize);
        
        return al;
}


void alist_free(struct Alist* al) 
{
        free(al->arry);
}


/*This function returns 0 if not found and 1 if found.
 *For speed's sake it does not check bounds, so be careful.
 */
inline int alist_find(struct Alist* al, int n) {
        return (al->arry[n/8] & (1 << (n%8)));
}


int divisorsum(int n);
struct Alist find_abundant_numbers(int max);
int is_abundant_sum(int n, struct Alist* al);


main() 
{
        struct Alist alist, *al;
        int n, sum = 0;

        alist = find_abundant_numbers(MAX);
        al = &alist;
        for (n = 2; n <= MAX; n++) {
                if (!is_abundant_sum(n, al))
                        sum += n;
        }
        printf("The sum of all numbers that aren't a sum of two"
               " abundant numbers is %d\n", sum);
        alist_free(al);
}


int divisorsum(int n)
{
        int max = n, sum = 1;
        int i;

        for (i = 2; i < max; i++) {
                if (n % i == 0) {
                        max = n / i;
                        sum += i;
                        if (max != i) 
                                sum += max;
                }
        }
        return sum;
}


struct Alist find_abundant_numbers(int max) 
{
        int i;
        struct Alist al;

        al = alist_new(max);
        for (i = 1; i <= max; i++) {
                if (divisorsum(i) > i) {
                        alist_add(&al, i);
                }
        }

        return al;
}


int is_abundant_sum(int n, struct Alist* al) 
{
        int i, j, max;
        int found = 0;      

        max = n / 2;
        for (i = 2; !found && i <= max; i++) {
                j = n - i;
                if (alist_find(al, i) && alist_find(al, j))
                        found = 1;
        }
        return found;
}


