#include <stdio.h>

int strlen(char s[])
{
    int l=0;
    while (s[l] != '\0')
        l++;
    return l;
}

int power(int base, int n)
{
    int p=1;
    while (n--)
        p = p * base;
    return p;
}

int htoi(char s[])
{
    int len = strlen(s)-1;
    int n = 0, index = 0;
    int i;

    /*
    printf("len(%s) = %d \n", s, len);
    for (i=0; i<5; i++) {
        printf("power(16, %d) = %d \n", i, power(16, i));
    }
    */
    
    for (i = len; s[i] != 'x' && s[i] != 'X'; i--)  {
        n += power(16, index) * (s[i] - '0');
        index++;
        // printf("i=%4d n=%4d \n", i, n);
    }
    
    return n;
}

int main()
{
    char a[] = "0x144";
    printf("%s = %d \n", a, htoi(a));

    return 0;
}
