#include <stdio.h>

#define MAXLINE 1000

void copy(char to[], char from[]);
int getline1(char line[], int maxlimit);

int main()
{
    char line[MAXLINE];
    char longest[MAXLINE];
    int len, max;

    max = 0;
    
    while ((len = getline1(line, MAXLINE)) > 0) {
        if (len > max) {
            copy(longest, line);
            max = len;
        }
    }

    if (max > 0) {
        printf("Longest line (%d): %s \n", max, longest);
    }

    return 0;
}

int getline1(char s[], int limit)
{
    int i, c;

    for (i=0; i<limit-1 && (c=getchar()) != EOF && c != '\n' ; i++)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    while(*to++ = *from++)
    ;
}
