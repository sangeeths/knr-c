#include <stdio.h>

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b; b = temp;
    return;
}

void swap_p(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void swap_pp(int **app, int **bpp)
{
    int *temp = NULL;
    temp = *app;
    *app = *bpp;
    *bpp = temp;
    return;
}

int main()
{
    int a, b;
    int *ap = &a;
    int *bp = &b;

    a = 10; b = 20;
    printf("a=%d ; b=%d \n", a, b);
    swap_v(a, b);
    printf("a=%d ; b=%d \n", a, b);
    swap_p(&a, &b);
    printf("a=%d ; b=%d \n", a, b);

    printf("pa=%d ; pb=%d \n", *ap, *bp);
    swap_pp(&ap, &bp);
    printf("pa=%d ; pb=%d \n", *ap, *bp);

    return 0;
}
