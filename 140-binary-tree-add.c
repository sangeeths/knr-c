#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct tnode {
    char * word;
    int count;
    struct tnode * left;
    struct tnode * right;
};

#define MAXLEN 100

int getword(char *word, int limit);
int strlen(char *str);
char * strcpy(char *to, char *from);
int strcmp(char *s1, char *s2);
char * strdup(char *word);
struct tnode * talloc(void);
struct tnode * addtree(struct tnode * node, char * word);
void treeprint(struct tnode * node);

int main()
{
    struct tnode *root = NULL;
    char word[MAXLEN];

    while (getword(word, MAXLEN) != EOF) 
        if (isalpha(word[0])) 
            root = addtree(root, word);

    treeprint(root);
    return 0;
}

int strlen(char *str)
{
    char *q = str;
    while(*str)
        str++;
    return str - q;
}

char * strcpy(char *to, char *from)
{  
    char *t = to;
    while (*to++ = *from++)
        ;
    return t;
}

char * strdup(char *str)
{
    char *p = NULL;
    if ((p = malloc(sizeof(char) * strlen(str)+1)) != NULL) 
        strcpy(p, str);
    return p;
}

int strcmp(char *s1, char *s2)
{
    while(*s1 == *s2) {
        if (*s1 == '\0')
            return 0;
        s1++; s2++;
    }
    return *s1 - *s2;
}

struct tnode * talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

int getword(char *word, int limit)
{
    int c;
    char *w = word;
    
    while (isspace(c = getch()))
        ;

    if(c != EOF)
        *w++ =  c;

    if(!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for( ; --limit > 0 ; w++) {
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s \n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode * addtree(struct tnode *p, char *word)
{   
    int result;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(word);
        p->count = 1;
        p->left = p->right = NULL;
        return p;
    }

    result = strcmp(word, p->word);
    if (result > 0) {
        p->right = addtree(p->right, word);
    } else if (result < 0) {
        p->left = addtree(p->left, word);
    } else {
        p->count++;
    }

    return p;
}
