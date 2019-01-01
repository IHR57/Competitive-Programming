#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 200005
using namespace std;

typedef long long ll;

ll tree[MAX];

void update(int idx, int n, int value)
{
    while(idx <= n){
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

ll query(int idx)
{
    ll sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

int main()
{
    int test, n, value;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        ll a[n+10], temp[n+10];

        memset(tree, 0, sizeof(tree));

        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            temp[i] = a[i];
        }

        sort(temp + 1, temp + n + 1);

        //Run binary search to find the position of a[i] in sorted array temp

        ll sum = 0;
        for(int i = 1; i <= n; i++){
            int idx = lower_bound(temp + 1, temp + n + 1, a[i]) - temp;
            sum += (query(n) - query(idx));        //number of value greater than a[i] in a[0] to a[i - 1];
            update(idx, n, 1);     //update with 1
        }

        printf("%lld\n", sum);

    }

    return 0;
}
