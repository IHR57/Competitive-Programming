#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, caseno = 1;
    double v1, v2, v3, a1, a2;

    scanf("%d", &test);

    while(test--){
        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
        double t1 = (v1 / a1);
        double t2 = (v2 / a2);
        double dist = (v1 * t1 - 0.5 * a1 * t1 * t1) + (v2 * t2 - 0.5 * a2 * t2 * t2);
        double bdist;
        if(t1 > t2)
            bdist = t1 * v3;
        else
            bdist = t2 * v3;

        printf("Case %d: ", caseno++);
        printf("%0.8lf %0.8lf\n", dist, bdist);
    }

    return 0;
}
