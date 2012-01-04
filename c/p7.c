/* p7.c - Project Euler problem 7
 *        Find the 10001st prime
 * Blake Mitchell, 2011
 */


#include <stdio.h>
#include "eutil.h"


unsigned int nth_prime(unsigned int n);
        
         
int main()
{
        int prime;

        prime = 10001;
        printf("The %d prime is %lu\n", prime, nth_prime(prime));
        return 0;
}


        

unsigned int nth_prime(unsigned int n)
{
        unsigned int i, previ;
        int p, pcount;
        
        previ = 1;
        i = 2;
        p = 0;
        pcount = 0;
        while (!p) {
                /* Overflow */
                if (previ > i) 
                        p = -1;
                else if (isprime(i)) 
                        pcount++;
                if (pcount == n) {
                        p = i;
                }
                previ = i;
                i++;
        }
                
        return p;
}
