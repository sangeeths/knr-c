#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

char * fgetc1(char *s, int limit, FILE *fp);
int fputc1(char *s, FILE *fp);
int getline1(char *line, int limit);
int strlen1(char *s);

int main()
{
    FILE *fp1, *fp2;
    char *filename1 = "test1.txt";
    char *filename2 = "test2.txt";
    char line[MAXLINE];

    if ((fp1 = fopen(filename1, "r")) == NULL) {
        printf("unable to open file : %s \n", filename1);
        exit(1);
    }
    
    if ((fp2 = fopen(filename2, "w")) == NULL) {
        printf("unable to open file : %s \n", filename2);
        exit(2);
    }

    fputc1(fgetc1(line, MAXLINE, fp1), fp2);

    fclose(fp2);
    fclose(fp1);

    printf("Enter line: \n");
    getline1(line, MAXLINE);
    printf("line : %s \n", line);
    
    return 0;
}

char * fgetc1(char *s, int limit, FILE *fp)
{
    int c;
    char *cs = s;

    while (--limit && (c = getc(fp)) != EOF) {
        if ((*cs++ = c) == '\n')
            break;
    }

    *cs = '\0';
    return (cs == s && c == EOF) ? NULL : s;
}

int fputc1(char *s, FILE *fp)
{
    int c;

    while(c = *s++)
        putc(c, fp);

    return ferror(fp) ? EOF : 0;
}

int strlen1(char *s)
{
    char *p = s;
    while(*s)
        s++;
    return s - p;
}

int getline1(char *line, int limit)
{
    if(fgets(line, limit, stdin) == NULL)
        return 0;
    else
        return strlen1(line);
}
