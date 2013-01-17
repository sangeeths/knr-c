#include <stdio.h>

int strlen1(char *p) 
{
    char *s = p;
    
    while (*p)
        p++;

    return p-s;
}

void trim(char a[])
{
    int len = strlen1(a) - 1;
    int i;

    for (i=len; i>=0 ; i--) {
        if (a[i] != ' ' && a[i] != '\n' && a[i] != '\t') {
            break;
        }
    }
    a[i+1] = '\0';

    return;
}

int main()
{
    char s[] = "this is a test string with  \t  \n\n";

    printf("===%s===\n", s);
    trim(s);
    printf("===%s===\n", s);

    return 0;
}
