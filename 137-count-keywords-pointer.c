#include <stdio.h>
#include <ctype.h>

#define MAXLEN 15

struct key {
    char *word;
    int count;
} keytable[] = {
    {"auto", 0}, 
    {"break", 0}, 
    {"case", 0}, 
    {"char", 0}, 
    {"const", 0}, 
    {"continue", 0}, 
    {"default", 0}, 
    {"else", 0}, 
    {"for", 0}, 
    {"int", 0}, 
    {"return", 0}, 
    {"unsigned", 0}, 
    {"void", 0}, 
    {"volatile", 0}, 
    {"while", 0}
};

void display_keytable(int len);
struct key * binary_search(char *key, int n);
int strcmp(char *s1, char *s2);
int getword(char *word, int limit);

int main()
{
    int len = sizeof(keytable) / sizeof(struct key);
    char word[MAXLEN];
    struct key * p;
    
    while (getword(word, MAXLEN) != EOF) {
        if(isalpha(word[0])) {
            if ((p = binary_search(word, len)) != NULL) {
                p->count++;
            }
        }
    }

    display_keytable(len);

    return 0;
}

void display_keytable(int len)
{
    int i;
    
    for (i=0; i<len ; i++)
        printf("%s [%d] \n", keytable[i].word, keytable[i].count);

    return;
}

struct key * binary_search(char *word, int n)
{
    struct key * low = &keytable[0];
    struct key * high = &keytable[n];
    struct key * mid;
    int result;

    while (low < high) {
        mid = low + (high - low) / 2;
        result = strcmp(word, mid->word);
        if (result < 0)
            high = mid;
        else if (result > 0)
            low = mid + 1;
        else 
            return mid;
    } 

    return NULL;
}

int strcmp(char *s1, char *s2)
{
    while (*s1 == *s2) {
        if (*s1 == '\0')
            return 0;
        s1++; s2++;
    }

    return *s1 - *s2;
}

int getword(char *word, int limit)
{
    int c;
    char * w = word;
        
    while (isspace(c = getch())) 
        ;

    if(c != EOF)
        *w++ =  c;
    
    if(!isalpha(c)) {
        *w = '\0';
        return c;
    }    

    for( ; --limit ; w++) {
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}
