#include <stdio.h>

#define XMAX 20
#define YMAX 20

struct point {
    int x;
    int y;
};

struct rect {
    struct point p1;
    struct point p2;
};

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);
void printpoint(char text[], struct point p);

int ptinrect(struct point p, struct rect r);


int main()
{
    struct rect screen;
    struct point middle;
    struct point add;

    screen.p1 = makepoint(0, 0);
    printpoint("screen p1", screen.p1); 

    screen.p2 = makepoint(XMAX, YMAX);
    printpoint("screen p2", screen.p2); 
   
    middle = makepoint((screen.p1.x + screen.p2.x)/2,
                       (screen.p1.y + screen.p2.y)/2);
    printpoint("middle", middle); 

    add = addpoint(screen.p1, screen.p2);    
    printpoint("add", add); 

    printf("%s\n", ptinrect(add, screen) ? "yes" : "no");
    printf("%s\n", ptinrect(middle, screen) ? "yes" : "no");
    printf("%s\n", ptinrect((struct point){1, 2}, screen) ? "yes" : "no");
    printf("%s\n", ptinrect((struct point){11, 22}, screen) ? "yes" : "no");
    printf("%s\n", ptinrect((struct point){111, 2}, screen) ? "yes" : "no");
    
    return 0;
}

struct point makepoint(int x, int y)
{
    struct point p = {x, y};
    return p;
}

struct point addpoint(struct point p1, struct point p2)
{
    return (struct point) {p1.x+p2.x, p1.y+p2.y};
}

void printpoint(char text[], struct point p)
{
    printf("%s : (%d, %d)\n", text, p.x, p.y);
    return;
}

/* 
NOTE: the two points given in the rect are 
      top left and bottom right.
      rect.p1 = top left
      rect.p2 = bottom right
*/
int ptinrect(struct point p, struct rect r)
{
    printpoint("point", p);
    printpoint("rect p1", r.p1);
    printpoint("rect p2", r.p2);

    return p.x >= r.p1.x &&
           p.x <= r.p2.x &&
           p.y >= r.p1.y &&
           p.y <= r.p2.y;
}

