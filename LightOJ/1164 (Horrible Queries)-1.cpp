#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

typedef long long int lint;

lint tree[3*MAX], lazy[3*MAX];

void update(int nodeNo, int low, int high, int x, int y, int value)
{
    if(x <= low && y >= high){      //if the node is relevant
        tree[nodeNo] += (high - low + 1) * value;
        lazy[nodeNo] += value;
        return;
    }

    int mid = (low + high) / 2;

    if(lazy[nodeNo] != 0){
        tree[nodeNo * 2] += (mid - low + 1) * lazy[nodeNo];     //add the propagate value to its left
        tree[nodeNo * 2 + 1] += (high - mid) * lazy[nodeNo];    //add the propagate value to its right
        lazy[nodeNo * 2] += lazy[nodeNo];
        lazy[nodeNo * 2 + 1] += lazy[nodeNo];
        lazy[nodeNo] = 0;       //propagate value of this node is NULL
    }

    if(x <= mid){
        update(nodeNo * 2, low, mid, x, y, value);
    }
    if(y > mid){
        update(nodeNo * 2 + 1, mid+1, high, x, y, value);
    }

    tree[nodeNo] = tree[nodeNo * 2] + tree[nodeNo * 2 + 1];
}

lint query(int nodeNo, int low, int high, int x, int y)
{
    lint p1 = 0, p2 = 0;

    if(x <= low && y >= high){
        return tree[nodeNo];
    }

    int mid = (low + high)>>1;

    if(lazy[nodeNo] != 0){
        tree[nodeNo * 2] += (mid - low + 1) * lazy[nodeNo];
        tree[nodeNo * 2 + 1] += (high - mid) * lazy[nodeNo];
        lazy[nodeNo * 2] += lazy[nodeNo];
        lazy[nodeNo * 2 + 1] += lazy[nodeNo];
        lazy[nodeNo] = 0;
    }

    if(x <= mid){
        p1 = query(nodeNo * 2, low, mid, x, y);
    }
    if(y > mid){
        p2 = query(nodeNo * 2 + 1, mid+1, high, x, y);
    }

    return p1 + p2;
}

int main()
{
    int test, cases = 1, n, q, command, idx1, idx2, value;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &q);

        //printf("Case %d:\n", cases++);

        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));

        for(int i = 0; i < q; i++){
            scanf("%d", &command);
            if(!command){       //if command = 0 then update
                scanf("%d %d %d", &idx1, &idx2, &value);
                update(1, 0, n-1, idx1-1, idx2-1, value);
            }
            else{
                scanf("%d %d", &idx1, &idx2);   //if command = 1 the answer the query
                lint result = query(1, 0, n-1, idx1-1, idx2-1);
                printf("%lld\n", result);
            }
        }
    }

    return 0;
}

