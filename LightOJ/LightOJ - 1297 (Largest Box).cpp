//Problem ID: LightOJ - 1297 (Largest Box)
//Programmer: IQBAL HOSSAIN     Description: MATH/Geometry
//Date: 28/06/19
//Helpful Link: https://www.youtube.com/watch?v=_oS_LjKse38
#include <bits/stdc++.h>
#define MAX 100005
#define EPS 1e-8
using namespace std;

typedef long long ll;

double a, b;

/*
    d(x) = (a - 2x) * (b - 2x) * x;
    d(x) = (ab - 2x(a + b) + 4x^2) * x
    d(x) = (abx - 2x^2(a + b) + 4x^3)
    d`(x) = (ab - 4x(a + b) + 12x^2)   ---first derivative of x
*/
bool check(double x)
{
    if((a * b - 4 * x * (a + b) + 12 * x * x) > 0){
        return true;
    }
    return false;
}

double findMax()
{
    double low = 0, high = b / 2, mid;
    while(high - low > EPS){
        mid = (low + high) / 2;
        if(check(mid)){
            low = mid;
        }
        else
            high = mid;
    }

    return (a - 2 * mid) * (b - 2 * mid) * mid;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, caseno =  1;

    scanf("%d", &test);

    while(test--){
        scanf("%lf %lf", &a, &b);

        double Max = 0.0;
        double res;

        res = findMax();
        if(res - Max > EPS)
            Max = res;

        printf("Case %d: %0.10lf\n", caseno++, Max);
    }

    return 0;
}