/* p19.c - Project Euler problem 19
 * Blake Mitchell, 2012
 */

#include <stdio.h>


#define ARRYSIZE(x) (sizeof(x)/sizeof(x[0]))
/* Day 0, Jan 1 1901, was a Tuesday */
#define IS_SUNDAY(d) (d % 7 == 5)
#define IS_LEAP_YEAR(y) ((y % 100) ? !(y % 4) : !(y % 400))


main()
{
        /* 30 days hath September... */
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year;
        int mi, fscount, day;

        fscount = 0;
        day = 0;
        for (year = 1901; year < 2001; year++) {
                for (mi = 0; mi < ARRYSIZE(months); mi++) {
                        if (IS_SUNDAY(day))
                                fscount ++;
                        day += months[mi];
                        if (mi == 1 && IS_LEAP_YEAR(year)) 
                                day ++; 
                }
        }

        printf("There were %d Sundays that fell on the first of the month between\n", fscount);
        printf("Jan 1, 1901 and Dec 31\n");

        return 0;
}
