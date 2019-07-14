//Problem ID: Hackerearth - Help Ashu
//Programmer: IQBAL HOSSAIN     Description: Segment Tree/Fenwick Tree
//Date: 04/07/19
//Problem Link: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/
#include <bits/stdc++.h>
#define MAX 100005
#define ff first
#define ss second
using namespace std;
 
typedef pair<int, int> pii;

pii tree[4*MAX];
int arr[MAX];
 
void build(int v, int l, int r)
{
    if(l == r){
        if(arr[l] % 2 == 1){
            tree[v].ff = 1, tree[v].ss = 0;
        }
        else
            tree[v].ff = 0, tree[v].ss = 1;
    }
    else{
        int mid = (l + r) >> 1;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        tree[v].ff = (tree[v*2].ff + tree[v*2+1].ff);
        tree[v].ss = (tree[v*2].ss + tree[v*2+1].ss);
    }
}
 
void update(int v, int l, int r, int pos, int val)
{
    if(l == r){
        if(val % 2)
            tree[v].ff = 1, tree[v].ss = 0;
        else
            tree[v].ff = 0, tree[v].ss = 1;
    }
    else{
        int mid = (l + r) >> 1;
        if(pos <= mid)
            update(v * 2, l, mid, pos, val);
        else
            update(v * 2 + 1, mid + 1, r, pos, val);
        tree[v].ff = tree[v*2].ff + tree[v*2+1].ff;
        tree[v].ss = tree[v*2].ss + tree[v*2+1].ss;
    }
}

pii query(int v, int l, int r, int i, int j)
{
    if(l > r || l > j || r < i)
        return make_pair(0, 0);

    if(l >= i && r <= j)
        return tree[v];
    int mid = (l + r) >> 1;
    pii p1 = query(v * 2, l, mid, i, j);
    pii p2 = query(v * 2 + 1, mid + 1, r, i, j);
    return make_pair(p1.ff + p2.ff, p1.ss + p2.ss);
}
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, caseno = 1;
    int n, q;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d",  &arr[i]);

    build(1, 1, n);
    scanf("%d", &q);

    int type, l, r, val;

    for(int i = 0; i < q; i++){
        scanf("%d %d %d", &type, &l, &r);
        if(type == 0){
            update(1, 1, n, l, r);
        }
        else{
            pii p = query(1, 1, n, l, r);
            (type == 1) ? printf("%d\n", p.ss) : printf("%d\n", p.ff);
        }
    }
 
    return 0;
}