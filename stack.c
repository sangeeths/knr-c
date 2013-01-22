#include <stdio.h>
#include "stack.h"

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: Stack full \n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("Error: Stack empty \n");
    return 0.0;
}

void print_stack(void)
{
    int i;
    for (i=0 ; i<sp; i++)
        printf("%5.2f\n", val[i]);
    return;
}
