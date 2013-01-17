#include <stdio.h>

#define MAXLINE 1000

int getline1(char line[], int limit);
int strindex(char source[], char pattern[]);

char pattern[] = "to";

int main()
{
    int found = 0; 
    char a[MAXLINE];

    while (getline1(a, MAXLINE) > 0) {
        if (strindex(a, pattern) >= 0) {
            printf("%s \n", a);
            found++;
        }
    }

    printf("found = %d \n", found);

    return 0;
}

int getline1(char s[], int lim)
{
    int c, i=0;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') 
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i=0; s[i] != '\0'; i++) {
        for (j=i, k=0 ; t[k] != '\0' && s[j] == t[k] ; j++, k++)
            ;
        if (k>0 && t[k] == '\0') 
            return i;
    }
    // printf("%s -> -1 \n", s);
    return -1;
}

