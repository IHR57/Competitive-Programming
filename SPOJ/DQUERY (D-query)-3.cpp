#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

struct data
{
    int l, r, next, ans;
} value[MAX];

int arr[MAX], last[MAX], Next[MAX], tree[4*MAX];

void update(int v, int low, int high, int pos, int val)
{
    if(low == high){
        tree[v] += val;
        return;
    }

    int mid = (low + high) >> 1;
    if(pos <= mid)
        update(v*2, low, mid, pos, val);
    else
        update(v*2+1, mid + 1, high, pos, val);

    tree[v] = tree[v*2] + tree[v*2+1];
}

int query(int v, int low, int high, int i, int j)
{
    if(low == i && high == j)
        return tree[v];

    int mid = (low + high) >> 1;

    if(j <= mid)
        return query(v*2, low, mid, i, j);

    else if(i > mid)
        return query(v*2+1, mid + 1, high, i, j);

    else return query(v*2, low, mid, i, mid) + query(v*2+1, mid + 1, high, mid + 1, j);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, caseNo = 1, n, q;
    int u, v;

    scanf("%d", &n);     //number of value and query

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &q);

    memset(last, -1, sizeof(last));
    memset(Next, -1, sizeof(Next));
    memset(tree, 0, sizeof(tree));

    for(int i = 0; i < q; i++){
        scanf("%d %d", &u, &v);
        u--, v--;       //0-based indexing
        value[i].l = u, value[i].r = v;
        value[i].next = Next[v];            //set next
        Next[v] = i;            //update next
    }

    for(int i = 0; i < n; i++){
        if(last[arr[i]] > -1)
            update(1, 0, n - 1, last[arr[i]], -1);      //which will subtract 1 in the last[arr[i]] th position.
        update(1, 0, n - 1, last[arr[i]] = i, 1);       //we need to store current position as last position for future

        for(int j = Next[i]; j > -1 ; j = value[j].next)
            value[j].ans = query(1, 0, n - 1, value[j].l, value[j].r);      //query in the interval l, r
    }

    for(int i = 0; i < q; i++)
        printf("%d\n", value[i].ans);

    return 0;
}
