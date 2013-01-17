#include <stdio.h>

#define FROM    1
#define TO   3000   

/*
Leap year:
year % 4 == 0 && year % 100 != 0
||
year % 400 == 0
*/

int leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
        return 1;
    return 0;
}

int main()
{
    int i;

    for (i=FROM; i<=TO; i++)
        if (leap_year(i))
            printf("%4d ", i);

    return 0;
}
