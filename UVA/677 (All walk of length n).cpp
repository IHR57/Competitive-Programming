#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 20
using namespace std;

int length, parent[MAX], visited[MAX], Count, walkofLength;
vector<int> graph[MAX];

void init()
{
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    //memset(depth, 0, sizeof(depth));
}

void print(int n)           //print the direction
{
    if(n == 1)
    {
        printf("%d", n);
        return;
    }

    print(parent[n]);
    printf(",%d", n);
}

void dfs1(int source)
{
    visited[source] = 1;

    if(Count == length){
        walkofLength++;
        printf("(");
        print(source);
        printf(")\n");
        return;
    }

    for(int i = 0; i < (int)graph[source].size(); i++){
        int v = graph[source][i];
        if(!visited[v]){
            Count++;
            parent[v] = source;
            dfs1(v);
            visited[v] = 0;         //we may need this again
            Count = Count - 1;      //decrement the count when we finished a node
        }
    }
}

int main()
{
    int n, m, value, temp = 0, x;

    while(scanf("%d %d", &n, &length) == 2){
        init();
        if(temp)
            printf("\n");
        temp = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &value);
                if(value == 1){
                    graph[i].push_back(j);
                    //graph[j].push_back(i);
                }
            }
        }
        Count = 0, walkofLength = 0;
        dfs1(1);

        if(!walkofLength)
            printf("no walk of length %d\n", length);
        for(int i = 0; i < MAX; i++)
            graph[i].clear();
        scanf("%d", &x);
    }

    return 0;
}
