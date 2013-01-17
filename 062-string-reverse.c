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

int main()
{
//    char s[] = "this is a string";
    char s[] = "gnirts a si siht";

    printf("%s\n", s);
    printf("%s\n", strrev(s));    

    return 0;
}
