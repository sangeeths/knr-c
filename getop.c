#include <stdio.h>
#include <ctype.h>

#include "getop.h"
#include "_getop.h"
#include "calc.h"

int getop(char s[])
{
    int i, c;

    /* skip spaces and tabs in the beginning */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    /* check for operators */
    /* not a number - could be +, -, *, / */
    if (!isdigit(c) && c != '.')
        return c;
        
    /* collect the integer part */
    i = 0;
    if (isdigit(c)) 
        while (isdigit(s[++i] = c = getch()))
            ;

    /* collect the fraction part */
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    //return 0;
    return NUMBER;
}
