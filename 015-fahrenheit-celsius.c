#include <stdio.h>

#define LOWER   0 
#define UPPER 300
#define STEP   20

int main()
{
    int fahr;

    /*
    float celsius;
    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr - 32);
        printf("%3d %6.1f \n", fahr, celsius);
        fahr += STEP;
    }
    */

    for (fahr = LOWER ; fahr <= UPPER ; fahr += STEP) {
        printf("%3d %6.1f \n", fahr, (5.0/9.0) * (fahr - 32));
    }

    return 0;
}
