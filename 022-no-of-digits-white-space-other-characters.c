#include <stdio.h>

/* nwhite = blankspace + tab + newline */

int main()
{
    int c, nwhite, nothers;
    int ndigits[10];
    int i;

    nwhite = nothers = 0;
    for (i=0 ; i<10 ;i++)
        ndigits[i] = 0;

    while ((c=getchar()) != EOF) {
        if (c >= '0' && c <= '9') 
            ndigits[c-'0']++;
        else if (c == ' ' || c == '\n' || c == '\t')
            nwhite++;
        else
            nothers++; 
    }

    printf("digits =");
    for (i=0 ; i<10 ;i++)
        printf(" %d", ndigits[i]);
    printf(", nwhite = %d, nothers = %d \n", 
           nwhite, nothers);

    return 0;
}
