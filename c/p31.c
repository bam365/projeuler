#include <stdio.h>


struct Coins {
        int onepound;
        int fiftyp;
        int twentyp;
        int tenp;
        int fivep;
        int twop;
        int penny;
};


int count_possibilities();
void iterate_onepound(struct Coins *c, int *count);
void iterate_fiftyp(struct Coins *c, int *count);
void iterate_twentyp(struct Coins *c, int *count);
void iterate_tenp(struct Coins *c, int *count);
void iterate_fivep(struct Coins *c, int *count);
void iterate_twop(struct Coins *c, int *count);
void iterate_penny(struct Coins *c, int *count);



main() 
{
        int num;

        printf("This takes several seconds...\n\n");
        num = count_possibilities();
        printf("The number of ways to make 2 British pounds from coins is\n"
               "%d\n", num);

        return 0;
}


int count_possibilities()
{
        struct Coins c;
        //Start with 8 to account for homogeneous combos
        int count = 8;

        iterate_onepound(&c, &count);

        return count;
}


//Iterate function loop counters, global for efficiency
static int I1LB, I50P, I20P, I10P, I5P, I2P, I1P;


void iterate_onepound(struct Coins *c, int *count) 
{
        for (I1LB = 0; I1LB < 2; I1LB++) {
                c->onepound = I1LB;
                iterate_fiftyp(c, count);
        }
}

void iterate_fiftyp(struct Coins *c, int *count) 
{
        for (I50P = 0; I50P < 4; I50P++) {
                c->fiftyp = I50P;
                iterate_twentyp(c, count);
        }
}

void iterate_twentyp(struct Coins *c, int *count) 
{
        for (I20P = 0; I20P < 10; I20P++) {
                c->twentyp = I20P;
                iterate_tenp(c, count);
        }
}

void iterate_tenp(struct Coins *c, int *count) 
{
        for (I10P = 0; I10P < 20; I10P++) {
                c->tenp = I10P;
                iterate_fivep(c, count);
        }
}

void iterate_fivep(struct Coins *c, int *count) 
{
        for (I5P = 0; I5P < 40; I5P++) {
                c->fivep = I5P;
                iterate_twop(c, count);
        }
}

void iterate_twop(struct Coins *c, int *count) 
{
        for (I2P = 0; I2P < 100; I2P++) {
                c->twop = I2P;
                iterate_penny(c, count);
        }
}

void iterate_penny(struct Coins *c, int *count)
{
        for (I1P = 0;I1P < 200; I1P++) {
                c->penny = I1P;
                if ((c->onepound*100 + c->fiftyp*50 + c->twentyp*20 +
                     c->tenp*10 + c->fivep*5 + c->twop*2 + c->penny) == 200) {
                        (*count)++;
                        //return;
                }
        }
}
