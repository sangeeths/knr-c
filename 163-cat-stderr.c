#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0];   /* program name to be printed on errors */
    
    if (argc == 1) {    /* no arguments: so copy stdin */
        filecopy(stdin, stdout);
    } else {
        while(--argc) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open file : %s \n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    
    if (ferror(stdout)) {
        fprintf(stderr, "%s: Error writing stdout\n", prog);
        exit(2);
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

