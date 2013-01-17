#include <stdio.h>

int power(int base, int n)
{
    int i;
    int p = 1;

    /*
    for (i=1; i<=n ; i++) 
        p = p * base;
    */

    while (n--) {
        p *= base;
    }

    return p;
}

int main()
{
    int i;

    for (i=0 ; i<10 ; i++) 
        printf("i=%d, power(2,%d)=%4d, power(-3,%d)=%7d\n",
               i, i, power(2,i), i, power(-3, i));  

    return 0;
}
