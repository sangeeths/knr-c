#include <stdio.h>

int main()
{   
    long nc = 0;
    int c;
    
    /*
    while((c = getchar()) != EOF)
        nc++;
    */

    for (nc = 0 ; getchar() != EOF ; nc++)
    ;

    printf("Number of chars: %ld \n", nc);    

    return 0;
}
