#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "stack.h"
#include "getop.h"

/*
$ gcc calc.c getop.c stack.c _getop.c 
$ ./a.out 
1 2 -
     -1 
1 2 - 4 5 + *
     -9 
10 15 * 3 10 * - 50 5 / + 
     130 
^C
$ 
*/

int main()
{

    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop()/op2);
            else
                printf("error: divide by zero \n");
            break;
        case '\n':
            printf("\t %.8g \n", pop());
            break;
        default:
            printf("error: unknown command \n");
        }
    }
    
    return 0;
}
