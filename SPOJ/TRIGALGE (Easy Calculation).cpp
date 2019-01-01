#include <bits/stdc++.h>
#define EPS 1e-8
using namespace std;

double a, b, c;

double f(double x)
{
    return a*x + b*sin(x);
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%lf %lf %lf", &a, &b, &c);
        double low = 0.0, high = 100000.0, mid;
        for(int i = 0; i < 100; i++){
            mid = (low + high) / 2.0;
            if(fabs(c - f(mid)) <= EPS){
                break;
            }
            if(f(mid) > c){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        printf("%0.8lf\n", mid);
    }

    return 0;
}
