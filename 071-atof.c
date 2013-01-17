#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
    int sign, i;
    double value, power;

    /* skip spaces */
    for (i=0 ; isspace(s[i]) ; i++)
        ;

    /* get the sign and skip it */
    sign = (s[i] == '-' ? -1 : 1);
    if (s[i] == '-' || s[i] == '+')
        i++;

    for (value = 0.0 ; isdigit(s[i]) ; i++) 
        value = value * 10.0 + (s[i]-'0');

    if (s[i] == '.') 
        i++;

    for (power = 1.0 ; isdigit(s[i]) ; i++) {
        value = value * 10.0 + (s[i]-'0');
        power = power * 10.0;
    }    
    
    return sign * value / power;
}

int main()
{
    // char a[] = "   -123.4567";
    char a[] = "         +9843.12322";
    
    printf("==%s==, ==%f== \n", a, atof(a));

    return 0;
}
