#include <stdio.h>

void filecopy(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[])
{
    FILE *fp;
    
    if (argc == 1) {    /* no arguments: so copy stdin */
        filecopy(stdin, stdout);
    } else {
        while(--argc) {
            if ((fp = fopen(*++argv, "r")) == NULL) { 
                printf("can't open file : %s \n", *argv);
                return 1;
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }

    return 0;
}

void filecopy(FILE *fp1, FILE *fp2)
{
    int c;
    while ((c=getc(fp1)) != EOF)
        putc(c, fp2);
    return; 
}

