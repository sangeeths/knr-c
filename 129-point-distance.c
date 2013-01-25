#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

double square(double x)
{
    return x * x;
}

double distance(struct point p1, struct point p2)
{
    return sqrt((square(p2.x - p1.x) + square(p2.y - p1.y)));
}

int main()
{

    struct point a, b;
    double dist; 

    /* point a = (-2, 1) */
    a.x = -2; a.y = -3;

    /* point b = (1, 5) */
    b.x = -4; b.y = 4;
    
    dist = distance(a, b);
        
    printf("distance : %0.2lf \n", dist);
    

    return 0;
}
