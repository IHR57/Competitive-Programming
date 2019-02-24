//Problem ID: LightOJ - 1275 (Internet Service Providers)
//Programmer: IQBAL HOSSAIN     Description: Math / Ternary Search
//Date: 20/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1275
/*
Notes: this problem can be solved without using ternary search
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

int ternarySearch()
{
    int low = 0, high = 1e8, m1, m2;
    while(high - low > 3){
        m1 = low + (high - low) / 3;
        m2 = high - (high - low) / 3;
        ll f1 = func(m1);
        ll f2 = func(m2);
        if(f1 < f2){
            low = m1;
        }
        else{
            high = m2;
        }
    }

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
