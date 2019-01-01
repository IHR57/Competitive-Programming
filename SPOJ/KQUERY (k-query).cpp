#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 300005
using namespace std;

vector<int> tree[4*MAX];

void build(int a[], int v, int low, int high)
{
    if(low == high){
        tree[v].push_back(a[low]);
    }
    else{
        int mid = (low + high) >> 1;
        build(a, v * 2, low, mid);
        build(a, v * 2 + 1, mid + 1, high);
        tree[v].resize(tree[v*2].size() + tree[v*2+1].size());
        merge(tree[v*2].begin(), tree[v*2].end(), tree[v*2+1].begin(), tree[v*2+1].end(), tree[v].begin());      //merging left and right child
        //this will sort the element between the range in ascending order
    }
}

int query(int v, int low, int high, int i, int j, int k)
{
    if(i > high || j < low)
        return 0;
    if(low >= i && high <= j){
        //vector<int>:: iterator pos = upper_bound(tree[v].begin(), tree[v].end(), k);
        return tree[v].end() - upper_bound(tree[v].begin(), tree[v].end(), k);
        //cout<<pos<<" "<<number<<endl;
        //if(number < 0)
          //  return 0;
    }

    int mid = (low + high) >> 1;

    return query(v * 2, low, mid, i, j,  k) + query(v * 2 + 1, mid + 1, high, i , j, k);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, q, arr[MAX], x, y, k;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    build(arr, 1, 1, n);        //build initial tree

    scanf("%d", &q);

    int lastAns = 0;
    while(q--){
        scanf("%d %d %d", &x, &y, &k);
        /*x = x ^ lastAns;
        y = y ^ lastAns;
        k = k ^ lastAns;

        if(x < 1)   x = 1;
        if(y > n)   y = n;
        if(x > y)
            lastAns = 0;
        else*/
            lastAns = query(1, 1, n, x, y, k);

        printf("%d\n", lastAns);
    }

    return 0;
}
