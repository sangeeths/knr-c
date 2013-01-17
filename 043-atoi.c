#include <stdio.h>

int atoi(char s[])
{
    int i, n=0;
    
    for (i=0; s[i] >= '0' && s[i] <= '9' ; i++)
        n = n * 10 + (s[i]-'0');
    
    return n;
}

int main()
{
    char a[] = "13579";

    printf("a=%s, value=%d\n", a, atoi(a));

    return 0;
}
