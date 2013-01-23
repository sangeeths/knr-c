#include <stdio.h>
#include "allocbuf.h"

int main()
{
    char * ptr1 = NULL;
    char * ptr2 = NULL;

    printbuf();
    ptr1 = alloc(500);
    printbuf();

    ptr2 = alloc(100);
    printbuf();

    afree(ptr1);
    printbuf();

    afree(ptr2);
    printbuf();
    
    return 0;
}
