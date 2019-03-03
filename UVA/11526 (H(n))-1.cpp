#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    int test;
    ll n;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        ll ans = n, prev = n, temp = n;

        if(n <= 0){
            printf("0\n");
            continue;
        }
        for(int i = 2; i <= temp; i++){
            temp = n / i;
            ans += (prev - temp) * (i - 1);
            if(temp > i - 1)
                ans += temp;
            prev = temp;
        }

        printf("%lld\n", ans);
    }

    return 0;
}

