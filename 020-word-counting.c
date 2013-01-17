#include <stdio.h>

#define IN  1
#define OUT 0

int main()
{
    int nl, nc, nw;
    int c, state;

    nl = nc = nw = 0;
    state = OUT;
    
    while((c = getchar()) != EOF) {
        /* character */
        nc++;

        /* line */
        if (c == '\n') 
            nl++; 
      
        /* word */
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            nw++;
        }
    }

    printf("Characters: %d, Words: %d, Lines: %d\n", nc, nw, nl);
    
    return 0;
}
