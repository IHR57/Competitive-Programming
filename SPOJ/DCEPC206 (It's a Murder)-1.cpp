#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 100005
using namespace std;

typedef long long ll;

ll tree[MAX];

void update(int idx, int n, int value)
{
    while(idx <= n){
        tree[idx] += (ll) value;
        idx += idx & (-idx);
    }
}

ll query(int idx)
{
    ll sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= idx & (-idx);
    }

    return sum;
}

int main()
{
    ll value, sum, temp;
    int pos, test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int arr[n+10], idx[n+10];

        memset(tree, 0, sizeof(tree));

        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            idx[i] = arr[i];            //copying into idx
        }

        sort(arr, arr+n);       //sort the initial array
        for(int i = 0; i < n; i++){
            int pos = lower_bound(arr, arr + n, idx[i]) - arr;      //position of each element in array
            idx[i] = pos;
        }

        sum = 0;
        for(int i = 0; i < n; i++){
            sum += query(idx[i]);
            update(idx[i]+1, n, arr[idx[i]]);
        }

        printf("%lld\n", sum);
    }

    return 0;
}
