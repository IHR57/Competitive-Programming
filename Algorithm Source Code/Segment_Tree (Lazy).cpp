#include <bits/stdc++.h>
#define MAX 7
using namespace std;

int tree[4*MAX], lazy[4*MAX], arr[MAX];

void build(int v, int l, int r)
{
    if(l == r){
        tree[v] = arr[l];;
        return;
    }
    int mid = (l + r) >> 1;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    tree[v] = (tree[v*2] + tree[v*2+1]);
}

void update(int v, int l, int r, int i, int j, int x)
{
    if(lazy[v] != 0){
        tree[v] += (r - l + 1) * lazy[v];
        if(l != r){
            lazy[v*2] += lazy[v];
            lazy[v*2+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(l > r || l > j || r < i)
        return;
    if(l >= i && r <= j){
        tree[v] += (r - l + 1) * x;
        if(l != r){
            lazy[v*2] += x;
            lazy[v*2+1] += x;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(v * 2, l, mid, i, j, x);
    update(v * 2 + 1, mid + 1, r, i, j, x);
    tree[v] = tree[v*2] + tree[v*2+1];
}

int query(int v, int l, int r, int i, int j)
{
    if(l > r || l > j || r < i)
        return 0;
    if(lazy[v] != 0){
        tree[v] += (r - l + 1) * lazy[v];
        if(l != r){
            lazy[v*2] += lazy[v];
            lazy[v*2+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(l >= i && r <= j)
        return tree[v];
    int mid = (l + r) >> 1;
    return query(v*2, l, mid, i, j) + query(v*2+1, mid+1, r, i, j);
}

int main()
{
    arr[0] = 2, arr[1] = 5, arr[2] = 9, arr[3] = 10, arr[4] = 4;
    arr[5] = 1, arr[6] = 15;
    int n = 7;
    build(1, 0, n - 1);
    cout<<query(1, 0, n - 1, 1, 3)<<endl;
    update(1, 0, n - 1, 1, 2, 5);
    cout<<query(1, 0, n - 1, 1, 3)<<endl;

    return 0;
}
