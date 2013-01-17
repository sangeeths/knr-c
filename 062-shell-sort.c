#include <stdio.h>

void print_array(int v[], int n)
{
    int i;

    for (i=0; i<n; i++)
        printf("%3d ",v[i]);

    printf("\n");
}

void shell_sort(int v[], int n)
{
    int gap, i, j, temp;
    
    for (gap = n/2 ; gap > 0 ; gap /= 2) {
        for (i = gap; i < n ; i++) {
            for (j = i-gap ; j >= 0 && v[j] > v[j+gap] ; j -= gap) {
                /* swap v[j] and v[j+gap] */
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
            // print_array(v, n); 
        }
        // printf("----------------------\n");
    }
}

int main()
{
    int a[] = {17, 3, 11, 5, 25, 12, 18, 7, 15, 6};
    int len = sizeof(a)/sizeof(a[0]);

    print_array(a, len); 
    shell_sort(a, len);
    print_array(a, len); 

    return 0;
}
