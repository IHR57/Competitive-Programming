#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 50005
using namespace std;

vector<int> graph, component;
vector<bool> visited;

int dfs(int u)
{
    visited[u] = true;
    int sum = 0;

    if(graph[u] != -1 && !visited[graph[u]]){
        sum += 1 + dfs(graph[u]);
    }
    visited[u] = false;
    component[u] = sum;

    return component[u];
}

int main()
{
    int test, caseno = 1, u, v, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        graph.assign(n+1,  -1);
        component.assign(n+1, -1);
        visited.assign(n+1, false);

        for(int i = 0; i < n; i++){
            scanf("%d %d", &u, &v);
            graph[u] = v;
        }

        int idx, Max = -1;

        for(int i = 1; i <= n; i++){
            if(component[i] == -1)
                dfs(i);
            if(component[i] > Max){
                Max = component[i];
                idx = i;
            }
        }

        printf("Case %d: %d\n", caseno++, idx);
    }

    return 0;
}
