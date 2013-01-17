#include <stdio.h>

int strlen1(char *p)
{
    char *s = p;
    while (*p)
        p++;
    return p-s;
}

char * strrev(char a[])
{
    int i = 0, j = strlen1(a)-1;
    int temp;
    
    while(i <= j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++; j--;
    }
    return a;
}

void itoa(int n, char s[])
{
    int i = 0;
    int sign = (n>0 ? 1: -1);

    if (sign <0) 
        n = -n;    

    while(n) {
        s[i] = (n%10) + '0';
        n /= 10;
        i++;
    }

    if (sign <0) 
        s[i++] = '-';
    
    s[i] = '\0';
    strrev(s);

    return;
}

int main()
{
    int i = -5467;
    char a[10];

    itoa(i, a);
    printf("%d, %s \n", i, a);

    return 0;
}
