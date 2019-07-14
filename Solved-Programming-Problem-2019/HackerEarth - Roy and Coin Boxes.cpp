//Problem ID: Hackerearth - Roy and Coin Boxes
//Programmer: IQBAL HOSSAIN     Description: Segment Tree/BIT
//Date: 04/07/19
//Problem Link: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/
#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;
 
int tree[4*MAX], lazy[4*MAX], arr[MAX], n;
 
 
void build(int v, int l, int r)
{
    if(l == r){
        arr[l] = tree[v];
    }
    else{
        int mid = (l + r) >> 1;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
    }
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
 
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, l, r, q, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &l, &r);
        update(1, 1, n, l, r, 1);
    }

    for(int i = 1; i <= n; i++)
        update(1, 1, n, i, i, 0);
    scanf("%d", &q);

    build(1, 1, n);

    int x;
    sort(arr + 1, arr + n + 1);

    for(int i = 0; i < q; i++){
        scanf("%d", &x);
        int idx = lower_bound(arr + 1, arr + n + 1, x) - arr;
        idx--;
        printf("%d\n", n - idx);
    }
 
    return 0;
}