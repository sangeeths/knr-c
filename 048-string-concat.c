#include <stdio.h>

char * strcat1(char dest[], char src[])
{
    int i=0, j=0;
    
    while(dest[i] != '\0')
        i++;

    while(src[j] != '\0')
        dest[i++] = src[j++];
    
    dest[i] = '\0';

    return dest;
}

char * strcat2(char *dest, char *src) 
{
    char *d = dest;

    while (*dest)
        dest++;

    while (*dest++ = *src++)
    ;

    return d;
}

int main()
{
    char s1[40] = "this is ";
    char s2[20] = "a test string..";

    printf("str1: %s \n", s1);
    printf("str2: %s \n", s2);
    // printf("%s \n", strcat1(s1, s2));
    printf("%s \n", strcat2(s1, s2));
   
    return 0;
}
