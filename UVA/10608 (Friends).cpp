#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define MAX 50010

int parent[MAX], setSize[MAX], Size[MAX];       //setSize of size of each node
int n;

void init()
{
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        Size[i] = 0;
        setSize[i] = 1;     //initially size of all node are 1
    }
}
int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
    if(!isSameSet(i, j)){
        int x = findSet(i);
        int y = findSet(j);

        //setSize[y] += setSize[x];

        if(Size[x] > Size[y]){
            parent[y] = x;
            setSize[x] += setSize[y];       //if Rank of x is greater than y then we increment the size of X
        }
        else{
            parent[x] = y;
            setSize[y] += setSize[x];
            if(Size[x] == Size[y]){
                Size[y]++;
            }
        }
    }
}

int main()
{
    int test, a, b, Max, edge;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &edge);

        init();
        Max = -1;
        for(int i = 0; i < edge; i++){
            scanf("%d %d", &a, &b);
            unionSet(a, b);
        }

        for(int i = 1; i <= n; i++){
            if(setSize[i] > Max){
                Max = setSize[i];
            }
        }

        printf("%d\n", Max);
    }

    return 0;
}
