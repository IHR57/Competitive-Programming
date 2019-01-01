#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 100005
using namespace std;

int arr[MAX], tree[3*MAX];
const int INF = 1 << 28;
void Insert(int nodeNo, int low, int high)
{
    if(low == high)     //when we have only single element
    {
        tree[nodeNo] = arr[low];
        return;
    }

    int leftChild = 2 * nodeNo;
    int rightChild = 2 * nodeNo + 1;
    int mid = (low + high) / 2;     //divide and conquer

    Insert(leftChild, low, mid);
    Insert(rightChild, mid+1, high);     //recursive call

    //we have to store minimum number in every node
    (tree[leftChild] < tree[rightChild]) ? tree[nodeNo] = tree[leftChild] : tree[nodeNo] = tree[rightChild];
}

int query(int nodeNo, int low, int high, int i, int j)
{
    if(i > high || j < low){    //if we go out of range
        return INF;
    }
    if(low >= i && high <= j){      //if we are in the range
        return tree[nodeNo];
    }

    int leftChild = 2 * nodeNo;
    int rightChild = 2 * nodeNo + 1;
    int mid = (low + high) / 2;

    int p1 = query(leftChild, low, mid, i, j);
    int p2 = query(rightChild, mid+1, high, i, j);

    //(p1 <= p2) ? return p1 : return p2;     //return the smallest in given range
    if(p1 <= p2)    return p1;
    else            return p2;
}

int main()
{
    int test, cases = 1, queryNumber, n, range1, range2;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &queryNumber);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);

        Insert(1, 1, n);

        printf("Case %d:\n", cases++);
        for(int i = 0; i < queryNumber; i++){
            scanf("%d %d", &range1, &range2);
            int result = query(1, 1, n, range1, range2);
            printf("%d\n", result);
        }
    }

    return 0;
}
