#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 200005
using namespace std;

int arr[MAX];
const int INF = 1 << 28;

struct info
{
    int minValue;
    int maxValue;
} tree[3*MAX];

void init(int nodeNo, int low, int high)
{
    if(low == high){
        tree[nodeNo].maxValue = arr[low];
        tree[nodeNo].minValue = arr[low];
        return;
    }

    int mid = (low + high) / 2;

    init(nodeNo * 2, low, mid);
    init(nodeNo * 2 + 1, mid+1, high);

    if(tree[nodeNo * 2].maxValue >= tree[nodeNo * 2 + 1].maxValue){
        tree[nodeNo].maxValue = tree[nodeNo * 2].maxValue;
    }
    else
        tree[nodeNo].maxValue = tree[nodeNo * 2 + 1].maxValue;

    if(tree[nodeNo * 2].minValue <= tree[nodeNo * 2 + 1].minValue)
        tree[nodeNo].minValue = tree[nodeNo * 2].minValue;
    else
        tree[nodeNo].minValue = tree[nodeNo * 2 + 1].minValue;
}

int queryMin(int nodeNo, int low, int high, int i, int j)
{
    if(i > high || j < low){
        return INF;
    }
    if(low >= i && high <= j){
        return tree[nodeNo].minValue;
    }

    int mid = (low + high)>>1;
    int p1, p2, temp;

    p1 = queryMin(nodeNo * 2, low, mid, i, j);
    p2 = queryMin(nodeNo * 2 + 1, mid+1, high, i, j);

    temp = min(p1, p2);

    return temp;
}

int queryMax(int nodeNo, int low, int high, int i, int j)
{
    if(i > high || j < low){
        return -INF;
    }
    if(low >= i && high <= j){
        return tree[nodeNo].maxValue;
    }

    int mid = (low + high)>>1;
    int p1, p2, temp;

    p1 = queryMax(nodeNo * 2, low, mid, i, j);
    p2 = queryMax(nodeNo * 2 + 1, mid+1, high, i, j);

    temp = max(p1, p2);

    return temp;
}
int main()
{
    int test, cases = 1, n, k;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        int Maxdiff = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }

        init(1, 1, n);
        for(int i = 1; i <= n - k + 1; i++){
            int value1 = queryMin(1, 1, n, i, i+k-1);
            int value2 = queryMax(1, 1, n, i, i+k-1);
           // printf("%d %d\n", value1, value2);
            int Max = value2 - value1;
            if(Max > Maxdiff)
                Maxdiff = Max;
        }
        printf("Case %d: %d\n", cases++, Maxdiff);
    }

    return 0;
}
