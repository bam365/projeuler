/* p30.c - Project Euler problem 30
 * Blake Mitchell, 2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define CHARTOINT(x) ((int)(x - '0'))



struct numlist_node {
        unsigned int d;
        struct numlist_node *next;
};


struct numlist {
        struct numlist_node *root;
        struct numlist_node *last;
};



struct numlist *numlist_new();
void numlist_free(struct numlist **nl);
struct numlist_node *numlist_add(struct numlist *nl, int d);
unsigned int numlist_summate(struct numlist *nl);
int ipow(int n, int pow);
unsigned int max_number(int pow);
unsigned int digit_power_sum(unsigned int n, int pow);



main() {
        unsigned int d;
        int pow = 5;
        int max = max_number(pow);
        struct numlist *nl;

        nl = numlist_new();

        for (d = pow; d <= max; d++) {
                if (d == digit_power_sum(d, pow)) 
                        numlist_add(nl, d);
        }

        printf("The sum of all numbers for which the sum of each digit to the %d"
               " power = the number itself\n is %d\n", pow, numlist_summate(nl));
                
        numlist_free(&nl);
        return 0;
}


struct numlist *numlist_new()
{
        struct numlist *nl;

        nl = (struct numlist*)malloc(sizeof(struct numlist));
        nl->root = NULL;
        nl->last = NULL;

        return nl;
}


void numlist_free(struct numlist **nl)
{
        struct numlist_node *nn, *next;

        for (nn = (*nl)->root; nn; nn = next) {
                next = nn->next;
                free(nn);
        }
        (*nl)->root = NULL;
        (*nl)->last = NULL;
        free(*nl);
}
        

struct numlist_node *numlist_add(struct numlist *nl, int d)
{
        struct numlist_node *nn;

        nn = (struct numlist_node*)malloc(sizeof(struct numlist_node));
        nn->d = d;
        nn->next = NULL;

        if (nl->root) 
                nl->last->next = nn;
        else 
                nl->root = nn;
        nl->last = nn;

        return nn;
}


unsigned int numlist_summate(struct numlist *nl)
{
        struct numlist_node *p;
        unsigned int sum = 0;

        for (p = nl->root; p; p = p->next)
                sum += p->d;

        return sum;
}


int ipow(int n, int pow)
{
        int ret, i;

        for (i = 0, ret = 1; i < pow; ret *= n, i++)
                ;

        return ret;
}


unsigned int max_number(int pow)
{
        int dig;
        unsigned int maxdig = ipow(9, pow);
         
        for (dig = 2; ipow(10, dig) < dig*maxdig; dig++) 
                ; 
        return (dig*maxdig);
}


unsigned int digit_power_sum(unsigned int n, int pow)
{
        static char NSTR[15]; 
        char *p;
        unsigned int sum = 0;

        sprintf(NSTR, "%u", n);
        for (p = NSTR; *p; p++)
                sum += ipow(CHARTOINT(*p), pow);

        return sum;
}
        


