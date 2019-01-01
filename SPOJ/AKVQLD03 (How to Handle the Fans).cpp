#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 1000005
using namespace std;

typedef long long ll;

ll tree[MAX];

void update(int idx, int n, int value)
{
    while(idx <= n){
        tree[idx] += (ll) value;
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
    int n, q, x, y;
    char str[100];

    scanf("%d %d", &n, &q);
    memset(tree, 0, sizeof(tree));

    while(q--){
        scanf("%s %d %d", str, &x, &y);
        if(strcmp(str, "add") == 0){
            update(x, n, y);
        }
        else{
            printf("%lld\n", query(y) - query(x-1));
        }
    }

    return 0;
}
