#include <stdio.h>

static char table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int leapyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int day_of_year(int year, int month, int day) 
{
    int leap = leapyear(year);
    int i;
    
    for (i=1; i<month; i++)
        day += table[leap][i];

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap = leapyear(year);
    int i;

    for (i = 1; yearday > table[leap][i]; i++)
        yearday -= table[leap][i];

    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int m, d;
    
    month_day(2012, 156, &m, &d);
    printf("%d - %d \n", m, d);
    
    month_day(2022, 56, &m, &d);
    printf("%d - %d \n", m, d);

    month_day(2001, 346, &m, &d);
    printf("%d - %d \n", m, d);

    printf("%d \n", day_of_year(2013, 4, 20));
    printf("%d \n", day_of_year(2012, 1, 22));
    printf("%d \n", day_of_year(2001, 8, 30));
    printf("%d \n", day_of_year(2016, 11, 4));
    printf("%d \n", day_of_year(2015, 12, 31));
    printf("%d \n", day_of_year(2016, 12, 31));

    return 0;
}
