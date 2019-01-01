#include <bits/stdc++.h>
#define EPS 1e-8
using namespace std;

double a, b, c;

double binarySearch()
{
    double p, q, r;
    double low = 0.0, high = a + b, mid;

    for(int i = 1; i <= 100; i++){
        mid = (low + high) / 2.0;
        p = sqrt(a * a - mid * mid);
        q = sqrt(b * b - mid * mid);
        r = (int) ((p * q) / (p + q));
        if(c - r > EPS)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return mid;
}

int main()
{
    int test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lf %lf %lf", &a, &b, &c);
        double result = binarySearch();
        printf("Case %d: %.8lf\n", caseNo++, result);
    }

    return 0;
}
