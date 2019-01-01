#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main()
{
    int t, l;
    double w, radius, circle, rectangle;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &l);
        w=(double)(l*6)/10;
        radius=(double)l/5;
        circle=PI*radius*radius;
        rectangle=(l*w)-circle;
        printf("%0.2lf %0.2lf\n", circle, rectangle);
    }

    return 0;
}
