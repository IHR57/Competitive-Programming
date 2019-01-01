#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 50010

int parent[MAX], Size[MAX];
int node, numOfDisjoint;

void init()
{
    for(int i = 0; i < node; i++){
        parent[i] = i;
        Size[i] = 0;
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
        numOfDisjoint--;
        int x = findSet(i);
        int y = findSet(j);

        if(Size[x] > Size[y]){
            parent[y] = x;
        }
        else{
            parent[x] = y;

            if(Size[x] == Size[y]){
                Size[y]++;
            }
        }
    }
}

int main()
{
    int edge, cases = 1, a, b;

    while(scanf("%d %d", &node, &edge)){
        if(node == 0 && edge == 0)
            break;

        numOfDisjoint = node;
        init();

        for(int i = 0; i < edge; i++){
            scanf("%d %d", &a, &b);
            unionSet(a, b);
        }

        printf("Case %d: %d\n", cases++, numOfDisjoint);
    }
}
