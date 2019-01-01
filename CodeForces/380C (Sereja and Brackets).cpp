#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1000005
using namespace std;

typedef pair<int, int> pii;
char str[MAX];

struct node
{
    int cs, o, c;       //cs - correct sequence, o - open bracket, c - close bracket
}tree[4*MAX];

node combine(node a, node b)
{
    node res;
    int temp = min(a.o, b.c);     //Minimum of open or close bracket
    res.cs = a.cs + b.cs + temp;     //increment correct sequence
    res.o = a.o + b.o - temp;        //subtract temp, as we've already taken this in correct sequence
    res.c = a.c + b.c - temp;

    return res;
}
void build(int nodeNo, int low, int high)
{
    if(low == high){
        if(str[low] == '('){
            tree[nodeNo].cs = tree[nodeNo].c = 0;
            tree[nodeNo].o = 1;
        }
        else{
            tree[nodeNo].cs = tree[nodeNo].o = 0;
            tree[nodeNo].c = 1;
        }
        return;
    }

    int mid = (low + high) >> 1;
    build(nodeNo * 2, low, mid);
    build(nodeNo * 2 + 1, mid + 1, high);

    tree[nodeNo] = combine(tree[nodeNo * 2], tree[nodeNo * 2 + 1]);
}

node query(int nodeNo, int low, int high, int l, int r)
{
    if(l == low && high == r)
        return tree[nodeNo];
    int mid = (low + high) >> 1;

    if(r <= mid){
        return query(nodeNo * 2, low, mid, l, r);
    }
    if(l > mid)
        return query(nodeNo * 2 + 1, mid + 1, high, l, r);

    return combine(query(nodeNo * 2, low, mid, l, mid), query(nodeNo * 2 + 1, mid + 1, high, mid + 1, r));
}

int main()
{
    int q;          //number of query
    scanf("%s", str);

    int n = strlen(str);

    scanf("%d", &q);

    int x,  y;

    build(1, 0, n - 1);

    for(int i = 0; i < q; i++){
        scanf("%d %d", &x, &y);
        x--, y--;           //0 based indexing
        node ans = query(1, 0, n - 1, x, y);
        printf("%d\n", ans.cs * 2);
    }

    return 0;
}
