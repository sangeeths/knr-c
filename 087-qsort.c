#include <stdio.h>

int a[] = {5, 7, 3, 2, 6, 4, 1, 9, 8, 10};

void display_array(int len)
{
    int i;
    
    for (i=0 ; i<len; i++)
        printf("%4d ", a[i]);
    printf("\n");

    return;
}

void swap(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    return;
}

void qsort(int v[], int left, int right)
{
    int i, last;
    int len = 10;

    if (left >= right)
        return;
    
    swap (v, left, (left+right)/2);
    last = left;

    for (i=left+1 ; i<=right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);

    return;
}

int main()
{
    int len = sizeof(a)/sizeof(a[0]);

    display_array(len);
    qsort(a, 0, len-1);
    display_array(len);

    return 0;
}
