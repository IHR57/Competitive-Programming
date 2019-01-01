// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

vector<int> graph[MAX];
int dist1[MAX], dist2[MAX], visited[MAX];

void dfs1(int u)
{
    visited[u] = 1;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dist1[v] = dist1[u] + 1;
            dfs1(v);
        }
    }
}

void dfs2(int u)
{
    visited[u] = 1;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dist2[v] = dist2[u] + 1;
            dfs2(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;

    cin>>n>>x;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(visited, 0, sizeof(visited));
    dfs1(1);
    memset(visited, 0, sizeof(visited));
    dfs2(x);

    int Max = -1;
    for(int i = 2; i <= n; i++){
        //cout<<dist1[i]<<" "<<dist2[i]<<endl;
        if(dist1[i] > dist2[i] && graph[i].size() == 1)
            Max = max(Max, dist1[i] * 2);
    }

    cout<<Max<<endl;

    return 0;
}
