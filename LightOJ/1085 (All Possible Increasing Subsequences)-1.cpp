#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#define MAX 100005
#define MOD 10000000007
using namespace std;

typedef long long ll;

ll tree[MAX];

void update(int idx, int n, ll value)
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
        sum = (sum + tree[idx]) % MOD;
        idx -= (idx & -idx);
    }

    return sum;
}

int main()
{
    int test, caseNo = 1, a[MAX], b[MAX], n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        map<int, int> M;
        memset(tree, 0, sizeof(tree));

        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }

        sort(b, b + n);

        int counter = 1;

        M[b[0]] = counter;      //mapping
        for(int i = 1; i < n; i++){
            if(b[i] != b[i-1]){
                M[b[i]] = ++counter;
            }
        }

        for(int i = 0; i < n; i++){
            ll val = query(M[a[i]] - 1) % MOD;
            update(M[a[i]], n, val+1);
        }

        printf("Case %d: %lld\n", caseNo++, query(n) % MOD);
    }

    return 0;
}
