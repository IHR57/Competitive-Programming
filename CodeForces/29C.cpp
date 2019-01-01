#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
int visited[MAX], org[MAX];

void dfs(int u)
{
    visited[u] = 1;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
    printf("%d ", org[u]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<int, int> myMap;
    int idx = 0, n, u, v, degree[MAX] = {0};

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>u>>v;
        if(myMap.find(u) == myMap.end()){
            myMap[u] = idx;
            org[idx] = u;
            idx++;
        }
        if(myMap.find(v) == myMap.end()){
            myMap[v] = idx;
            org[idx] = v;
            idx++;
        }
        int x = myMap[u];
        int y = myMap[v];
        graph[x].push_back(y);
        graph[y].push_back(x);
        degree[x]++, degree[y]++;
    }

    for(int i = 0; i < idx; i++){
        if(degree[i] ==  1){
            dfs(i);
            break;
        }
    }

    printf("\n");

    return 0;
}
