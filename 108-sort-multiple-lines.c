#include <stdio.h>
#include "allocbuf.h"

#define MAXLINES 1000
#define LINESIZE 1000

int getline1(char line[], int maxline);
int getlines(char *lineptr[], int maxlines);
void printlines(char *lineptr[], int maxlines);
char * strcpy(char *s1, char *s2);
int strcmp(char *s1, char *s2);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

/* array of character pointes to hold the lines */
char *lineptr[MAXLINES];


int main()
{
    int nlines = 0;

    if ((nlines = getlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printlines(lineptr, nlines);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    } else {
        printf("error in reading lines \n");
    }

    return 0;
}



int strcmp(char *s1, char *s2)
{
    while (*s1 == *s2) {
        if (*s1 == '\0')
            return 0;
        s1++; s2++;
    }

    return *s1 - *s2;
}

void swap(char *v[], int i, int j)
{
    char * temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    return;
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    
    if (left >= right)  /* recurssion termination condition */
        return;
    
    swap(v, left, (left+right)/2);
    last = left;
    
    for (i=left+1 ; i<=right ; i++) 
        if (strcmp(v[i], v[left]) < 0) 
            swap(v, ++last, i);
    
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

char * strcpy(char *s1, char *s2)
{
    char *p = s1;
    while (*s1++ = *s2++) 
        ;
    return p;
}

int getline1(char line[], int limit)
{
    int i, c;
    
    for (i=0; i<limit-1 && (c=getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        i++;
    }
    
    line[i] = '\0';
    
    return i;
}

int getlines(char *lineptr[], int maxlines)
{
    int len;
    int nlines = 0;
    char line[LINESIZE];
    char *p = NULL;

    while((len = getline1(line, LINESIZE)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
 
    return nlines;
}

void printlines(char *lineptr[], int maxlines)
{   
    int i;

    /*
    for (i=0; i<maxlines; i++)
        printf("%s \n", lineptr[i]);
    */

    while (maxlines-- > 0) 
        printf("%s \n", *lineptr++);
   
    return;
}


