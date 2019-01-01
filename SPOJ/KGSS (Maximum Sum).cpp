#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 100005
using namespace std;

int arr[MAX], Mx, sndMx;

struct node
{
    int Max, secondMax;
}tree[4*MAX];

priority_queue <int> pq;

void init(int nodeNo, int low, int high)
{
    if(low == high){
        tree[nodeNo].Max = arr[low];
        tree[nodeNo].secondMax = -1;
        return;
    }

    int left = nodeNo * 2;
    int right = nodeNo * 2 + 1;
    int mid = (low + high) / 2;

    init(left, low, mid);
    init(right, mid + 1, high);

    if(tree[left].Max >= tree[right].Max){
        tree[nodeNo].Max = tree[left].Max;
        tree[nodeNo].secondMax = max(tree[right].Max, tree[left].secondMax);
    }
    else{
        tree[nodeNo].Max = tree[right].Max;
        tree[nodeNo].secondMax = max(tree[left].Max, tree[right].secondMax);
    }
}

void update(int nodeNo, int low, int high, int idx, int value)
{
    if(idx > high || idx < low)
        return;
    if(low >= idx && high <= idx){
        tree[nodeNo].Max = value;
        tree[nodeNo].secondMax = -1;
        return;
    }

    int left = nodeNo * 2;
    int right = nodeNo * 2 + 1;
    int mid = (low + high) / 2;

    update(left, low, mid, idx, value);
    update(right, mid + 1, high, idx, value);

    if(tree[left].Max >= tree[right].Max){
        tree[nodeNo].Max = tree[left].Max;
        tree[nodeNo].secondMax = max(tree[right].Max, tree[left].secondMax);
    }
    else{
        tree[nodeNo].Max = tree[right].Max;
        tree[nodeNo].secondMax = max(tree[left].Max, tree[right].secondMax);
    }
}

void query(int nodeNo, int low, int high, int i, int j)
{
    if(i > high || j < low)
        return;
    if(low >= i && high <= j){
        pq.push(tree[nodeNo].Max);
        pq.push(tree[nodeNo].secondMax);
        return;
    }

    int left = nodeNo * 2;
    int right = nodeNo * 2 + 1;
    int mid = (low + high) / 2;

    query(left, low, mid, i, j);
    query(right, mid + 1, high, i, j);
}

int main()
{
    int n, q, x, y, ans;
    char ch[100];

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    init(1, 1, n);

    scanf("%d", &q);

    while(q--){
        scanf("%s %d %d", ch, &x, &y);
        if(ch[0] == 'Q'){
            query(1, 1, n, x, y);
            Mx = pq.top();
            pq.pop();
            sndMx = pq.top();
            pq.pop();

            printf("%d\n", Mx + sndMx);

            while(!pq.empty()){
                pq.pop();
            }
        }
        if(ch[0] == 'U'){
            update(1, 1, n, x, y);
        }
    }

    return 0;
}
