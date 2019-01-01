#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int test, caseNo = 1;
    double a, b, c, d, ab, ad, cd, bc;

    scanf("%d" ,&test);

    while(test--){
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        ab = max(a, c);
        cd = min(a, c);
        ad = max(b, d);
        bc = min(b, d);
        
        double t = abs(ab - cd);
        double temp = ad * ad;
        double x = abs((((bc * bc) - (t * t) - temp)) / (2 * t));
        double h = sqrt(temp - (x * x));
        double Area = ((ab + cd) * h) / 2;

        printf("Case %d: %.7lf\n", caseNo++, Area + 1e-8);
    }

    return 0;
}