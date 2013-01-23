#include <stdio.h>

int strcmp1(char *s, char *t)
{
    int i =0 ;
    
    for(i=0 ; s[i] == t[i] ; i++) {
        if (s[i] == '\0')
            return 0;
    }
    
    return s[i] - t[i];
}

int strcmp2(char *s, char *t)
{
    while (*s == *t) {
        if (*s == '\0')
            return 0;
        s++; t++;
    }

    return *s - *t;
}

int main()
{
    /*
    char str1[] = "ramdom tect";
    char str2[] = "ramdom tebt";
    */

    char str1[] = "618ml4gcfP55XE8BjI";
    char str2[] = "601zJ51eokS7kd2y3Z";
    // char str2[] = "6O1zJ51eokS7kd2y3Z";

    int result = strcmp2(str1, str2);

    printf("str1 : %s \n", str1);
    printf("str2 : %s \n", str2);
    
    if (result > 0) {
        printf("str1 > str2\n");
    } else if (result < 0) {
        printf("str1 < str2\n");
    } else {
        printf("str1 = str2 \n");
    }

    return 0;
}
