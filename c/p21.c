/* p21.c - Project Euler problem 21 
 *         Find the sum of all amicable pairs under 10000 
 * Blake Mitchell, 2011
 */

#include <stdio.h>
#include <stdlib.h>


struct plist 
{
        int num;
        struct plist* next;
};


struct plist* plist_hit(struct plist* pl, int num);
struct plist* plist_insert(struct plist* prev, struct plist* next, int n);
void  plist_free(struct plist* root);
int plist_sum(struct plist *root);

int divsum(int n);
int apair_sum(int n);



int main()
{
        int max;

        max = 10000;
        printf("The sum of amicable pairs under %d is %d\n", max,
                        apair_sum(max));
        return 0;
}



struct plist* plist_hit(struct plist* pl, int num)
{
        struct plist *n, *prevn, *new;

        prevn = NULL;
        n = pl;
        new = NULL;
        while (n != NULL && new == NULL) {
                if (n->num == num) {
                        return pl;
                } else if (n->num > num) {
                        new = plist_insert(prevn, n, num);
                } else {
                        prevn = n;
                        n = n->next;
                }
        }
        if (new == NULL) 
                new = plist_insert(prevn, NULL, num);
         
        return ((prevn == NULL) ? new : pl); 
}

               
struct plist* plist_insert(struct plist* prev, struct plist* next, int n)
{
        struct plist *new;

        new = (struct plist*)malloc(sizeof(struct plist));
        new->num = n;
        new->next = next;
        if (prev != NULL)
                prev->next = new;
        
        return new;
}


void  plist_free(struct plist* root)
{
        struct plist *n, *tmp;
        
        n = root;
        while (n != NULL) {
                tmp = n->next;
                free(n);
                n = tmp;
        }
} 


int plist_sum(struct plist *root)
{
        struct plist *n;
        int sum;

        n = root;
        sum = 0;
        while (n != NULL) {
                sum += n->num;
                n = n->next;
        }

        return sum;
}


int divsum(int n) 
{
        int i, sum;

        sum = 0;
        for (i = 2; i <= (n / i) ; i++) {
                if ((double)(n) / i == (double)(n / i)) {
                        sum += i;
                        sum += n / i;
                }
        }
        return (sum + 1);
}


int apair_sum(int n)
{
        struct plist *root;
        int i, dsum, asum;

        root = NULL;
        for (i = 0; i < n; i++) {
                dsum = divsum(i);
                if (dsum == i) 
                        continue;
                else if (divsum(dsum) == i) {
                        root = plist_hit(root, i);
                        root = plist_hit(root, dsum);
                }
        }
        asum = plist_sum(root); 

        free(root);
        return asum;
}
