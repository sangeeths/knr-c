#include <stdio.h>

int strlen1(char arr[])
{
    int len = 0;

    while (arr[len] != '\0')
        len++;

    return len;
}

int strlen2(char *ptr)
{
    int len = 0;

    while (*ptr++)
        len++;

    return len;
}

int strlen3(char *ptr)
{
    char *sptr = ptr;
    
    while (*ptr)
        ptr++;

    return ptr - sptr;
}

int main()
{   
    char a[] = "this is a string";
    char *p = "this is another string";

    printf("strlen1(%s) = %d \n", a, strlen1(a));
    printf("strlen1(%s) = %d \n", p, strlen1(p));

    printf("strlen2(%s) = %d \n", a, strlen2(a));
    printf("strlen2(%s) = %d \n", p, strlen2(p));

    printf("strlen3(%s) = %d \n", a, strlen3(a));
    printf("strlen3(%s) = %d \n", p, strlen3(p));

    return 0;
}
