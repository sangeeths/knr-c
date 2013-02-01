#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main()
{
    minprintf("%s, %d, %f \n", "test string", 1, 2.0);
    minprintf("%s\n", "string alone");
    minprintf("%d\n", 100);
    minprintf("%f\n", 300.12);
    return 0;
}

void minprintf(char *fmt, ...)
{
    va_list ap;
    int ival;
    char *sval, *p;
    double dval;

    va_start(ap, fmt);
    for(p = fmt; *p ; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'd':   ival = va_arg(ap, int);
                        printf("%d", ival); 
                        break;
            case 's':   for (sval = va_arg(ap, char *) ; *sval ; sval++)
                            putchar(*sval);
                        break;
            case 'f':   dval = va_arg(ap, double);
                        printf("%f", dval);
                        break;
            default:
                break;
        }
    }
    va_end(ap);
    return;
}
