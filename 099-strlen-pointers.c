#include <stdio.h>

int strlen_a(char a[])
{
    int len = 0;

    while (a[len] != '\0')
        len++;    

    return len;
}

int strlen_p(char *p)
{
    char *q = p;

    while (*p)
        p++;
    
    return p - q;
}

int main()
{
    char a[] = "array string";
    char *ptr = "pointer string";

    printf("a[] = %s ; len = %d\n", a, strlen_a(a));
    printf("ptr = %s ; len = %d\n", ptr, strlen_p(ptr));
        
    return 0;
}
