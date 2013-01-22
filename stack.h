#ifndef _STACK_
#define _STACK_

#define MAXVAL 100

int sp;
double val[MAXVAL];

void push(double f);
double pop(void);
void print_stack(void);

#endif
