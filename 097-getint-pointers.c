#include <stdio.h>
#include <ctype.h>

#include "_getop.h" /* getch() and ungetch() */

#define SIZE 10

void display_array(int array[], int n)
{   
    int i;
    
    for (i=0 ;i<n ; i++)
        printf("%5d ", array[i]);
    printf("\n");
    return;
}

int getint(int *pn)
{
    int c, sign;

    /* skip spaces */
    while(isspace(c = getch())) 
        ;
    
    /* return 0 if not a number */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    /* if sign is present, get it, and get 
       one more character from getch() 
    */
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
        c = getch();

    /* convert character to integer */
    *pn = 0;
    while (isdigit(c)) {
        *pn = *pn * 10 + (c - '0');
        c = getch();
    }
    
    *pn = *pn * sign;

    if (c != EOF)
        ungetch(c);    

    return c;
}

int main()
{
    int array[SIZE];
    int n;

    for (n=0; n<SIZE && getint(&array[n]) != EOF ; n++)
        ;

    display_array(array, n);    

    return 0;
}
