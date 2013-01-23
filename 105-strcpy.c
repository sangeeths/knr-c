#include <stdio.h>

char * strcpy1(char *to, char *from)
{
    char * s = to;
    while (*to++ = *from++)
        ;
    return s;
}

int main()
{
    char str1[100] = "this is a string..";
    char str2[] = "adding a new one now";

    printf("string 1 : %s \n", str1);
    printf("string 2 : %s \n", str2);
    printf("copied str: %s \n", strcpy1(str1, str2));

    return 0;
}
