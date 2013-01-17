#include <stdio.h>
#include <ctype.h>

int atoi(char s[])
{
    int sign, n, i;

    /* skip spaces */
    for (i=0; isspace(s[i]); i++)
    ;

    /* skip sign */    
    sign = (s[i] == '-' ? -1 : 1);
    if (s[i] == '-' || s[i] == '+')
        i++;

    /* atoi */
    for (n=0 ; isdigit(s[i]); i++) 
        n = n * 10 + (s[i] - '0');

    return sign * n;
}

int main()
{
    char a[] = "   +34254";

    printf("a=%s, i=%d \n", a, atoi(a));

    return 0;
}
