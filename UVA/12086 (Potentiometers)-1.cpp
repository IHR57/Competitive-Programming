#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 200005
using namespace std;

int tree[4*MAX];

void build(int a[], int nodeNo, int low, int high)
{
    if(low == high){
        tree[nodeNo] = a[low];
        return;
    }
    else{
        int mid = (low + high) >> 1;
        build(a, nodeNo * 2, low, mid);
        build(a, nodeNo * 2 + 1, mid + 1, high);
        tree[nodeNo] = tree[nodeNo * 2] + tree[nodeNo * 2 + 1];
    }
}

void update(int nodeNo, int low, int high, int pos, int value)
{
    if(low == high){
        tree[nodeNo] = value;
    }
    else{
        int mid = (low + high) >> 1;
        if(pos <= mid)
            update(nodeNo * 2, low, mid, pos, value);
        else
            update(nodeNo * 2 + 1, mid + 1, high, pos, value);
        tree[nodeNo] = tree[nodeNo * 2] + tree[nodeNo * 2 + 1];
    }
}

int query(int nodeNo, int low, int high, int i, int j)
{
    if(i > high || j < low)
        return 0;
    if(low >= i && high <= j){
        return tree[nodeNo];
    }

    int mid = (low + high) >> 1;

    return query(nodeNo * 2, low, mid, i, j) + query(nodeNo * 2 + 1, mid + 1, high, i, j);
}

int main()
{
    int n, x, y, arr[MAX], line = 0, caseNo = 1;

    while(scanf("%d", &n) == 1){
        if(!n)  break;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        build(arr, 1, 0, n - 1);

        char str[100];

        if(line)    printf("\n");
        line = 1;

        printf("Case %d:\n", caseNo++);

        while(scanf("%s", str) && strcmp(str, "END") != 0){
            scanf("%d %d", &x, &y);
            if(str[0] == 'S'){
                x--;
                update(1, 0, n - 1, x, y);
            }
            else if(str[0] == 'M'){
                x--, y--;
                int ans = query(1, 0, n - 1, x, y);
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}
