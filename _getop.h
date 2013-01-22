#ifndef _GETOP_LIB_
#define _GETOP_LIB_

#define BUFSIZE 100

char buf[BUFSIZE];
char bufp;

int getch(void);
void ungetch(int c);
void printbuf(void);

#endif

