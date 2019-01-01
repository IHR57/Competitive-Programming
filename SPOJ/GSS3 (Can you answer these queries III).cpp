#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 51000
using namespace std;

const int inf = 15008;

struct node
{
    int sum, prefix, suffix, ans;
}tree[4*MAX];

node combine(node l, node r)
{
    node res;
    res.sum = l.sum + r.sum;
    res.prefix = max(l.prefix, l.sum + r.prefix);
    res.suffix = max(r.suffix, r.sum + l.suffix);
    res.ans = max(max(l.ans, r.ans), l.suffix + r.prefix);
    return res;
}

void build(int a[], int nodeNo, int low, int high)
{
    if(low == high){
        tree[nodeNo].sum = tree[nodeNo].prefix = tree[nodeNo].suffix = tree[nodeNo].ans = a[low];
        return;
    }
    else{
        int mid = (low + high) >> 1;
        build(a, nodeNo * 2, low, mid);
        build(a, nodeNo * 2 + 1, mid + 1, high);
        tree[nodeNo] = combine(tree[nodeNo * 2], tree[nodeNo * 2 + 1]);
    }
}

void update(int nodeNo, int low, int high, int idx, int value)
{
    if(low == high){
        tree[nodeNo].sum = tree[nodeNo].prefix = tree[nodeNo].suffix = tree[nodeNo].ans = value;
        return;
    }
    else{
        int mid = (low + high) >> 1;
        if(idx <= mid)
            update(nodeNo * 2, low, mid, idx, value);
        else
            update(nodeNo * 2 + 1, mid + 1, high, idx, value);
        tree[nodeNo] = combine(tree[nodeNo * 2], tree[nodeNo * 2 + 1]);
    }
}

node query(int nodeNo, int low, int high, int i, int j)
{
    if(i == low && high == j)
        return tree[nodeNo];
    int mid = (low + high) >> 1;

    if(j <= mid){
        return query(nodeNo * 2, low, mid, i, j);
    }
    if(i > mid)
        return query(nodeNo * 2 + 1, mid + 1, high, i, j);

    return combine(query(nodeNo * 2, low, mid, i, mid), query(nodeNo * 2 + 1, mid + 1, high, mid + 1, j));
}

int main()
{
    int n, m, x, y, arr[MAX], chk;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    build(arr, 1, 0, n - 1);     //initialize tree

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        scanf("%d", &chk);
        if(chk == 0){
            scanf("%d %d", &x, &y);
            x--;
            update(1, 0, n - 1, x, y);
        }
        else if(chk == 1){
            scanf("%d %d", &x, &y);
            x--, y--;
            node result = query(1, 0, n - 1, x, y);
            printf("%d\n", result.ans);
        }
    }

    return 0;
}
