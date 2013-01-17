#include <stdio.h>

int main()
{
    long lc = 0;
    int c;

    while ((c=getchar()) != EOF) {
        if (c == '\n')
            lc++;
    }

    printf("Number of lines : %ld \n", lc);

    return 0;
}
