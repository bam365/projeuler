/* lcm.c - Project Euler problem number 5, find LCM of numbers 1-20
 * Blake Mitchell, 2011
 */

#include <stdio.h>
#include <stdlib.h>


struct plist_node
{
        int prime;
        int count;
        struct plist_node* next;
};


struct plist_node* plist_new();
int plist_hit(int n, struct plist_node *root);
int plist_hit_greatest(int n, int c, struct plist_node *root);
int plist_product(struct plist_node *root);
void plist_free(struct plist_node *root);
void plist_insert(int i, int init, struct plist_node *lastnode);
int primefact(int n, struct plist_node* pl);
int isprime(int n);
void make_lcm_plist(struct plist_node **plarry, struct plist_node *lcmpl,
                    int num);
/* Finds LCM of all factors from 2 to n */
int  lcmrange(int n);




int main()
{
        printf("LCM of all factors between 2 and %d: %d\n", 20, lcmrange(20));

        return 0;
}


struct plist_node* plist_new(int p)
{
        struct plist_node* n;
        
        n = (struct plist_node*)malloc(sizeof(struct plist_node));
        n->prime = p;
        n->count = 0;
        n->next = NULL;

        return n;
}


int plist_hit(int n, struct plist_node* root)
{
        struct plist_node *node, *lastnode, *newnode;

        node = root;
        lastnode = NULL;
        while (node != NULL)
        {
                if (node->prime == n) {
                        node->count++;
                        return node->count;
                }
                /*This lists are ordered least to greatest*/
                else if (node->prime > n) {
                        plist_insert(n, 1, lastnode);
                        return newnode->count;
                }
                lastnode = node;
                node = node->next;
        }
        /* Have a new highest prime node */
        plist_insert(n, 1, lastnode);
        return 1;
}


int plist_hit_greatest(int n, int c, struct plist_node* root)
{
        struct plist_node *node, *lastnode, *newnode;

        node = root;
        lastnode = NULL;
        while (node != NULL)
        {
                if (node->prime == n) {
                        if (c > node->count)
                                node->count = c;
                        return node->count;
                }
                /*This lists are ordered least to greatest*/
                else if (node->prime > n) {
                        plist_insert(n, c, lastnode);
                        return newnode->count;
                }
                lastnode = node;
                node = node->next;
        }
        /* Have a new highest prime node */
        plist_insert(n, c, lastnode);
        return 1;
}


void plist_insert(int i, int init, struct plist_node *lastnode)
{
        struct plist_node* newn;

        newn = plist_new(i);
        newn->count = init;
        if (lastnode != NULL)
                lastnode->next = newn;
}


int plist_product(struct plist_node *root)
{
        int i, prod;
        struct plist_node *n;

        prod = 1;
        n = root;
        while (n != NULL) {
               if (n->prime) 
                       for (i = 0; i < n->count; i++)
                               prod *= n->prime;
               n = n->next;
        } 
        return prod;
}
        

void plist_free(struct plist_node *root)
{
        struct plist_node *n, *nextn;

        n = root;
        while (n != NULL) {
                nextn = n->next;
                free(n);
                n = nextn;
        }
}

int isprime(int n)
{
        int i;

        if (n <= 1) 
                return 0;
        
        for(i = 2; i <= n / i; i++)
                if ((double)(n)/i == (double)(n/i))
                        return 0;
        return 1;
}


int primefact(int n, struct plist_node *pl)
{
        int i;

        if (isprime(n))
        {
                plist_hit(n, pl);
                return 1;
        }

        for (i = 2; i <= n; i++) {
                if (isprime(i) && (double)(n)/(double)i == (double)(n/i)) {
                        n /= i;
                        plist_hit(i, pl);
                        i = 1;
                }
        }
        return 0;
}


void make_lcm_plist(struct plist_node **plarry, struct plist_node *lcmpl,
                    int num)
{
        int i;
        struct plist_node *n;
        
        for (i = 0; i < num; i++) {
                n = plarry[i];
                while (n != NULL) {
                        plist_hit_greatest(n->prime, n->count, lcmpl);
                        n = n->next;
                }
        } 
}


int  lcmrange(int n)
{
        int i, fac, lcm, plcount;
        struct plist_node **plarry;
        struct plist_node *lcmpl;

        plcount = n - 1;
        plarry = (struct plist_node**)
                  malloc(sizeof(struct plist_node*) * plcount);
        for (fac = 2; fac <= n; fac++) {
               plarry[fac-2] = plist_new(0);
               primefact(fac, plarry[fac-2]);
        }
        lcmpl = plist_new(0);
        make_lcm_plist(plarry, lcmpl, plcount);
        lcm = plist_product(lcmpl);
        for (i = 0; i < plcount; i++)
                plist_free(plarry[i]);
        free(plarry);

        return lcm;
}
        


