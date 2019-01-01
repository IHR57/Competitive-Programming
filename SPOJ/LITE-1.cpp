#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100005
using namespace std;

int tree[4*MAX], lazy[4*MAX];

void shift(int id, int low, int high)
{
    tree[id] = (high - low + 1) - tree[id];
    if(low != high){
        lazy[id*2] ^= 1;
        lazy[id*2+1] ^= 1;
    }

}

void update(int id, int low, int high, int x, int y)
{
    if(lazy[id]){
        shift(id, low, high);
        lazy[id] = 0;
    }
    if(x > y || x > high || y < low)
        return;
    if(low >= x && high <= y){
        shift(id, low, high);
        return;
    }

    int mid = (low + high) >> 1;

    update(id*2, low, mid, x, y);
    update(id*2+1, mid + 1, high, x, y);

    tree[id] = tree[id*2] + tree[id*2+1];
}


int query(int id, int low, int high, int x, int y)
{
    if(lazy[id]){
        shift(id, low, high);
        lazy[id] = 0;
    }
    if(x > y || x > high || y < low)
        return 0;
    if(low >= x && high <= y){
        return tree[id];
    }

    int mid = (low + high) >> 1;

    return query(id*2, low, mid, x, y) + query(id*2+1, mid + 1, high, x, y);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, q, x, y, cmd;

    scanf("%d %d", &n, &q);

    while(q--){
        scanf("%d %d %d", &cmd, &x, &y);
        x--, y--;
        if(cmd == 1){
            int ans = query(1, 0, n - 1, x, y);
            printf("%d\n", ans);
        }
        else
            update(1, 0, n - 1, x, y);
    }

    return 0;
}
