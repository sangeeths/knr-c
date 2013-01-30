#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 101
#define MAXLEN 20 

struct nlist {
    struct nlist * next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

int strlen(char *str);
char * strcpy(char *to, char *from);
char * strdup(char *str);
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void printhash(void);
int getword(char *word, int limit);

int main()
{
    install("Ahead", "BlackBerry");
    install("But", "Canadian");
    install("Capital", "Chief");
    install("Eric", "Executive");
    install("February", "Heins");
    // printhash();
    install("Ironfire", "Jackson, ");
    install("LLC", "New");
    install("Partner", "RIM");
    install("Thorsten", "U.S.");
    install("York", "abandoning");
    install("after", "already");
    // printhash();
    install("also", "although");
    install("analysts", "and");
    install("announced", "any");
    install("as", "at");
    install("back", "be");
    install("becomes", "before");
    // printhash();
    install("biggest", "black");
    install("call", "carrier");
    install("clues", "company");
    install("date", "delay");
    install("delays", "devices");
    // printhash();
    install("disappointment", "few");
    install("for", "founder");
    install("fresh", "get");
    install("going", "had");
    install("has", "his");
    install("hopes", "in");
    printhash();
    // install("inception", "initially");
    install("is", "it");
    install("its", "itself");
    install("launch", "launch.");
    install("long", "managing");
    install("mark", "meant.");
    // printhash();
    install("name", "need");
    install("new", "of");
    install("offered", "on");
    install("on-your-hip", "one");
    install("operating", "pioneered");
    install("planned", "point");
    install("pushed", "reflected");
    // printhash();
    install("said", "signaling");
    install("signature", "since");
    install("smartphones", "so");
    install("start", "starting");
    install("struggled", "system.");
    install("take", "testing, ");
    install("that", "the");
    // printhash();
    install("to", "twice");
    install("used", "was");
    install("what", "which");
    install("will", "with");
    install("work", "would");
    printhash();

    lookup("will");
    lookup("abc");
    lookup("operating");
    lookup("reflected");
    lookup("to");

    return 0;
}

int strlen(char *s)
{
    char *q=s;
    while(*s)
        s++;
    return s-q;
}

char * strcpy(char *to, char *from)
{
    char *t = to;
    while(*to++ = *from++)
        ;
    return t;
}

char * strdup(char *str)
{
    char *s = NULL;
    if ((s = (char *) malloc(sizeof(char) * strlen(str)+1)) != NULL)
        strcpy(s, str);
    return s;
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

unsigned hash(char *s)
{
    unsigned hashval;
    for(hashval = 0; *s != '\0' ; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL ; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            printf("%s is present in the hash - %s \n", s, np->defn);
            return np;
        }
    }

    printf("%s is not present in the hash \n", s);
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        if ((np = (struct nlist *) malloc(sizeof(struct nlist))) == NULL)
            return NULL;
        if ((np->name = strdup(name)) == NULL) 
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free(np->defn);
    }

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;

    return np;
}

void printhash(void)
{
    int i;
    struct nlist *np = NULL;

    for (i=0; i<HASHSIZE ; i++) {
        if (hashtab[i] != NULL) {
            printf("hashtable[%d] \n", i);
            for (np = hashtab[i]; np != NULL; np=np->next)
                printf("%s -> %s \n", np->name, np->defn);
        }
    }

    return;
}

