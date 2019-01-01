#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 30005
using namespace std;

char str[MAX];

struct node
{
    int sum, minSum;
} tree[4*MAX];

void init(int nodeNo, int low, int high)
{
    if(low == high){
        tree[nodeNo].sum = tree[nodeNo].minSum = (str[low] == '(') ? 1 : -1;
            return;
    }

    int left = 2 * nodeNo;
    int right = 2 * nodeNo + 1;
    int mid = (low + high) / 2;

    init(left, low, mid);       //left subtree
    init(right, mid + 1, high);     //right subtree

    tree[nodeNo].sum = tree[left].sum + tree[right].sum;
    tree[nodeNo].minSum = min(tree[left].minSum, tree[left].sum + tree[right].minSum);
}

void update(int nodeNo, int low, int high, int idx)
{
    if(idx > high || idx < low)     //if cross the boundary
        return;
    if(low == idx && high == idx){
        if(str[idx] == '('){
            str[idx] = ')';
            tree[nodeNo].sum = tree[nodeNo].minSum = -1;
        }
        else{
            str[idx] = '(';
            tree[nodeNo].sum = tree[nodeNo].minSum = 1;
        }
        return;
    }

    int left = 2 * nodeNo;
    int right = 2 * nodeNo + 1;
    int mid = (low + high) / 2;

    update(left, low, mid, idx);
    update(right, mid + 1, high, idx);

    tree[nodeNo].sum = tree[left].sum + tree[right].sum;
    tree[nodeNo].minSum = min(tree[left].minSum, tree[left].sum + tree[right].minSum);
}

int main()
{
    int n, query, q, caseNo = 1;

    for(int i = 0; i < 10; i++){
        scanf("%d", &n);
        getchar();
        scanf("%s", str+1);
        init(1, 1, n);

        scanf("%d", &query);

        printf("Test %d:\n", caseNo++);

        while(query--){
            scanf("%d", &q);
            if(q == 0){
                if(tree[1].sum == 0 && tree[1].minSum == 0){        //if balanced
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
            }
            else{
                update(1, 1, n, q);
            }
        }
    }

    return 0;
}
