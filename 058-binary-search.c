#include <stdio.h>

#define ASIZE 15

void print_array(int a[], int size)
{
    int i;
    for (i=0; i<size; i++)
        printf("%d, ", a[i]);
    printf("\n");
    return;
}

int binsearch(int x, int v[], int n)
{
    int low, mid, high;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid]) 
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    } 
   
    return -1;
}

int main()
{
    int v[ASIZE] = {2, 5, 7, 9, 11, 13, 15, 18, 20, 25, 26, 29, 35, 37, 50};
    int x;  /* element to be searched */

    print_array(v, ASIZE);

    x = 10;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 1;      printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 100;    printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 33;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 37;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 15;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 2;      printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    x = 50;     printf("x=%3d, index=%2d \n", x, binsearch(x, v, ASIZE));
    
    return 0;
}
