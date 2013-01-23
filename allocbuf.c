#include <stdio.h>
#include "allocbuf.h"

#define BUFSIZE 1000000

static char allocbuf[BUFSIZE];
static char *allocp = allocbuf;

char * alloc(int n)
{
    if (allocbuf + BUFSIZE - allocp > n) {
        allocp = allocp + n;
        return allocp - n;
    } else {
        return 0;   /* not enough space */
    }
}

void afree(char *p)
{
    if (p > allocbuf && p < allocbuf+BUFSIZE)
        allocp = p;
}

void printbuf()
{
    if (allocp == allocbuf) {
        printf("Buffer ALL empty\n");
    } else if (allocp == allocbuf+BUFSIZE) {
        printf("Buffer ALL full \n");
    } else {
        printf("FULL: allocbuf:%p  to  allocp=%p\n", allocbuf, allocp);
        printf("FREE: allocp=%p to end=%p \n", allocp, allocbuf+BUFSIZE);
    }
}

