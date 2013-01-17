#include <stdio.h>

/*
EOF = -1 
    
In Windows  : Ctrl-Z 
In Linux    : Ctrl-D

If you are on a line that's not empty, you will 
have to double press ^D: Pressing it one time 
will flush that line, pressing it another time 
will send EOF. If you are on an empty line, 
one ^D is enough.
*/

int main()
{
    int c;
    
    while ((c = getchar()) != EOF)
        putchar(c);
    
    return 0;
}
