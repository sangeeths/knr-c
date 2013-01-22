#include <stdio.h>

#include "_getop.h"

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many arguments \n");
    else
        buf[bufp++] = c;
}

void printbuf(void)
{
    int i;

    printf("printbuf: ");
    for (i=0 ; i<bufp; i++)
        printf("%c ", buf[i]);
    printf("\n");
}
