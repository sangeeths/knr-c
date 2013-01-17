#include <stdio.h>

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c+'a'-'A';
    return c;
}

int main()
{
    printf("%c = %c \n", 'E', lower('E'));
    printf("%c = %c \n", 'Z', lower('Z'));
    printf("%c = %c \n", 'a', lower('a'));
    printf("%c = %c \n", 'O', lower('O'));
    printf("%c = %c \n", 't', lower('t'));
    
    return 0;
}
