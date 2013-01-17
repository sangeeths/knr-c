#include <stdio.h>

void squeeze(char s[], int c)
{
    int i, j;

    for (i=j=0; s[i] != '\0' ; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
    return;
}

int main()
{
    char str[] = "this is a test string";

    printf("%s\n", str);
    squeeze(str, 's');
    printf("%s\n", str);
    squeeze(str, 't');
    printf("%s\n", str);

    return 0;
}
