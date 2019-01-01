#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#define MAX 10005
using namespace std;

int tree[4*MAX], lazy[4*MAX], arr[MAX], mark[1000005];

void genSieve()
{
    int limit = (int) sqrt(1000005);

    mark[1] = 1;
    for(int i = 4; i < 1000005; i += 2)
        mark[i] = 1;

    for(int i = 3; i < 1000005; i += 2){
        if(!mark[i]){
            if(i <= limit){
                for(int j = i * i; j < 1000005; j += i *2){
                    mark[j] = 1;
                }
            }
        }
    }
}

void build(int id, int low, int high)
{
    if(low == high){
        tree[id] = arr[low];
        lazy[id] = arr[low];
    }
    else{
        int mid = (low + high) >> 1;
        build(id*2, low, mid);
        build(id*2+1, mid + 1, high);
        tree[id] = tree[2*id] + tree[2*id+1];
    }
}

void shift(int id, int low, int high, int x)
{
    tree[id] = (high - low + 1) * x;
    if(low != high){
        lazy[2*id] = lazy[2*id+1] = x;
    }
    lazy[id] = -1;
}

void update(int id, int low, int high, int i, int j, int value)
{
    if(lazy[id] != -1){
        shift(id, low, high, lazy[id]);
    }
    if(low > high || i > high || j < low)
        return;
    if(low >= i && high <= j){
        shift(id, low, high, value);
        return;
    }

    int mid = (low + high) >> 1;
    update(id*2, low, mid, i, j, value);
    update(id*2+1, mid + 1, high, i, j, value);

    tree[id] = tree[2*id] + tree[2*id+1];
}

int query(int id, int low, int high, int i, int j)
{
    if(lazy[id] != -1){
        shift(id, low, high, lazy[id]);
    }

    if(low > high || i > high || j < low)
        return 0;
    if(low >= i && high <= j){
        return tree[id];
    }

    int mid = (low + high) >> 1;

    return query(id*2, low, mid, i, j) + query(id*2+1, mid + 1, high, i, j);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test, n, q, x, y, value, cmd, caseNo = 1;
    genSieve();

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &q);
        memset(lazy, -1, sizeof(lazy));
        for(int i = 0; i < n; i++){
            scanf("%d", &value);
            if(!mark[value])
                arr[i] = 1;
            else
                arr[i] = 0;
        }

        build(1, 0, n - 1);

        printf("Case %d:\n", caseNo++);

        for(int i = 0; i < q; i++){
            scanf("%d", &cmd);
            if(!cmd){
                scanf("%d %d %d", &x, &y, &value);
                x--, y--;
                if(!mark[value]){     //if it is prime then update the interval with 1
                    update(1, 0, n - 1, x, y, 1);
                }
                else
                    update(1, 0, n - 1, x, y, 0);
            }
            else{
                scanf("%d %d", &x, &y);
                x--, y--;
                int ans = query(1, 0, n - 1, x, y);     //number of prime between x and y
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}
