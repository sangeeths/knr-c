#include <stdio.h>

void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

int main()
{
    int n = 1234;
    printd(n);
    printf("\n");
    return 0;
}
