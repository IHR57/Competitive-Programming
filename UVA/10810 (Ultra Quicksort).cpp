#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 500005
using namespace std;

typedef long long ll;

ll bit[MAX];
int a[MAX], b[MAX];

void update(int idx, int n, int value)
{
    while(idx <= n){
        bit[idx] += (ll) value;
        idx += (idx & -idx);
    }
}

ll query(int idx, int n)
{
    ll sum = 0;

    while(idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

int main()
{
    int n;

    while(scanf("%d", &n) == 1){
        if(n == 0)  break;
        memset(bit, 0, sizeof(bit));

        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }

        sort(b, b + n);

        ll sum = 0;

        for(int i = n-1; i >= 0; i--){
            int idx = lower_bound(b, b + n, a[i]) - b + 1;
            //cout<<idx<<endl;
            ll temp = query(idx - 1, n);
            sum += temp;
            update(idx, n, 1);
        }

        printf("%lld\n", sum);
    }

    return 0;
}
