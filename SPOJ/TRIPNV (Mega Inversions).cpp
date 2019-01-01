#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100005
using namespace std;

typedef long long ll;

ll arr[MAX], bit[MAX], bigger[MAX], smaller[MAX];

ll getSum(int idx, int n)
{
    ll sum = 0;

    while(idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

void update(int idx, int n, int value)
{
    while(idx <= n){
        bit[idx] += value;
        idx += (idx & -idx);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    memset(bit, 0, sizeof(bit));
    for(int i = n-1; i >= 0; i--){
        smaller[i] = getSum(arr[i]-1, n);
        update(arr[i], n, 1);
    }

    memset(bit, 0, sizeof(bit));

    for(int i = 0; i < n; i++){
        bigger[i] = i - (getSum(arr[i], n));
        update(arr[i], n, 1);
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){
        ans += (bigger[i] * smaller[i]);
    }

    printf("%lld\n", ans);

    return 0;
}
