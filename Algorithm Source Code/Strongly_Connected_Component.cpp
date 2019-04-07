#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

vector<int> graph[MAX], rgraph[MAX];
int visited[MAX], finish[MAX], finishing_time;

void dfs(int u)
{
    finishing_time++;
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
    finish[u] = ++finishing_time;
}

void dfs2(int u)
{
    visited[u] = 1;
    for(int i = 0; i < rgraph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v])
            dfs(v);
    }
}

int main()
{
    int n, m, u, v;

    scanf("%d %d", &n, &m);     //number of node and edge
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i);
    }
    vector<pair<int, int> > vp;
    for(int i = 1; i <= n; i++){
        vp.push_back(make_pair(finish[i], i));
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());

    int scc = 0;
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++){
        int m = vp[i].second;
        if(!visited[m]){
            scc++;
            dfs2(m);
        }
    }

    printf("Number of connected Component: %d\n", scc);

    return 0;
}
