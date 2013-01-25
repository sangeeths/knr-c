#include <stdio.h>
#include <string.h>

#define MAXLINE 500

int getline1(char line[], int limit);

/* ./a.out -x -n pattern .... ... ..  */

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int lineno = 0;
    int expect = 0, number = 0;
    int c;

    while (--argc && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch(c) {
            case 'x':   expect = 1;
                        break;
            case 'n':   number = 1;
                        break;
            default:    printf("Illegal operation: %c \n", c);  
                        return 0;
            }
        }
    }
    
    if (argc != 1) {
        printf("Usage: ./a.out -x -n pattern .. .. .. \n");
        return 0;
    } 

    while (getline1(line, MAXLINE) > 0) {
        lineno++;
        if ((strstr(line, *argv) != NULL) != expect) {
            if (number) 
                printf("%d: ", lineno);
            printf("%s \n", line); 
        }
    }
    
    return 0;
}

int getline1(char line[], int limit)
{
    int i, c;

    for (i=0 ; i<limit-1 && (c=getchar()) != EOF && c != '\n' ; i++) 
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        i++;
    }
    
    line[i] = '\0';

    return i;
}

