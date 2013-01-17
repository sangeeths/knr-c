#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

int strlen(char *s)
{
    char *p = s;
    while (*p)
        p++;
    return p - s;
}

char * strrev(char a[])
{
    int i, j;
    char temp;

    for (i=0, j=strlen(a)-1 ; i<j ; i++, j--) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;    
    }   

    return a;
}

void d2b(unsigned n)
{
    char s[20] = {0};
    int i = 0;
    int num = n;

    while(n) {
        s[i++] = (n % 2) + '0';
        n /= 2;  
    }
    s[i] = '\0';
    strrev(s);

    printf("%5d %s \n", num, s);
    return;
}

int main()
{
    unsigned int x = 222;
    int p = 6;
    int n = 5;
    unsigned int result = getbits(x, p, n);

    printf("x=%u, p=%d, n=%d, result=%u\n", x, p, n, result);
    d2b(x);
    d2b(result);

    return 0;
}
