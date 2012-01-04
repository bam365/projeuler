/* eutil.h - Utilities for Project Euler problems
 * Blake Mitchell 2011
 */


#define TODIGIT(x)              ((char)((x) + '0'))
#define FROMDIGIT(x)            ((int)((x) - '0')) 
#define ISDIGIT(x)              (x >= '0' && x <= '9')



int inttostr(unsigned long n, char *str, int max);
int addstr_inplace(char *summand, char *sum, int max);
void shift_left(char *nstr, int n, int max);
int multch(char *fac, char n, char *prod, int max);
int multstr(char *fac1, char *fac2, char *prod, int max);
int factorial(unsigned short n, char *fac, int max);
int digitsum(char *n, int max);
void strnum_reverse(char *n, int max);
int powstr(unsigned short n, unsigned short p, char *fac, int max);
int isprime(unsigned int n);
