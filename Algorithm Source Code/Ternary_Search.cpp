/*
    Problem ID: LightOJ - 1275 (Internet Service Providers)

    Given profit = T * (C - T * N);
    where C and N will be given, we have to  compute the smallest value of T that maximizes the total profit

    this function is unimodal (increasing -> decreasing or decreasing -> increasing) that's why we can use ternary search

    References: https://cp-algorithms.com/num_methods/ternary_search.html
                https://www.hackerearth.com/practice/algorithms/searching/ternary-search/tutorial/
*/

#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll n, c;

ll func(int m)
{
    ll temp = (c - (m * n));
    if(temp < 0)
        return -1;
    return m * temp;
}

double ternarySearchDouble(double l, double r)
{
    double eps = 1e-9;

    while(r - l > eps){         //we can use constant number of iteration with this (200 - 300 is enough for this)
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = func(m1);
        double f2 = func(m2);
        if(f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return func(l);
}

int ternarySearch()     //for integer
{
    int low = 0, high = 1e8, m1, m2;
    while(high - low > 3){
        m1 = low + (high - low) / 3;
        m2 = high - (high - low) / 3;
        ll f1 = func(m1);
        ll f2 = func(m2);
        if(f1 < f2){        //the desired maximum located on the interval (m1, r)
            low = m1;
        }
        else{
            high = m2;
        }
    }

    //our result lies into this range i.e: (low, low + 1, low + 2)
    //we have to find out the minimum index for which it produces maximum result
    if(func(low + 1) > func(low)){
        if(func(low + 2) > func(low + 1)){
            return low + 2;
        }
        return low + 1;
    }

    return low;
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &n, &c);
        if(n == 0){
            printf("Case %d: 0\n", caseno++);
            continue;
        }
        int result = ternarySearch();

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
