#include <stdio.h>
#include <math.h>

int main()
{
    double u, v, t, s, a;
    int n, i=0;
    while(scanf("%d", &n)==1){
        if(n==0)
            break;
        switch(n)
        {
        case 1:
            scanf("%lf %lf %lf", &u, &v, &t);
            s=(u+v)*t/2;
            a=(v-u)/t;
            i++;
            printf("Case %d: %0.3lf %0.3lf\n", i, s, a);
            break;
        case 2:
            scanf("%lf %lf %lf", &u, &v, &a);
            t=(v-u)/a;
            s=(u+v)*t/2;
            i++;
            printf("Case %d: %0.3lf %0.3lf\n", i, s, t);
            break;
        case 3:
            scanf("%lf %lf %lf", &u, &a, &s);
            v=sqrt(u*u+2*a*s);
            t=(v-u)/a;
            i++;
            printf("Case %d: %0.3lf %0.3lf\n", i, v, t);
            break;
        case 4:
            scanf("%lf %lf %lf", &v, &a, &s);
            u=sqrt(v*v-2*a*s);
            t=(v-u)/a;
            i++;
            printf("Case %d: %0.3lf %0.3lf\n", i, u, t);
            break;
        }
    }

    return 0;
}
