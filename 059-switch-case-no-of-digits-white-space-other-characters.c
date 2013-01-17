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
        switch(c) {
            case '0': case '1': case '2':
            case '3': case '4': case '5':
            case '6': case '7': case '8':
            case '9':
                ndigits[c-'0']++;
                break;  
            case '\t':
            case '\n':
            case ' ' :
                nwhite++;
                break;
            default:
                nothers++; 
        }
    }

    printf("digits =");
    for (i=0 ; i<10 ;i++)
        printf(" %d", ndigits[i]);
    printf(", nwhite = %d, nothers = %d \n", 
           nwhite, nothers);

    return 0;
}
