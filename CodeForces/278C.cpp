#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
int visited[MAX];

void dfs(int u)
{
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, u, v;

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        for(int j = 1; j <= x; j++){
            cin>>u;
            graph[i].push_back(n + u);
            graph[n+u].push_back(i);
        }
    }

    memset(visited, 0, sizeof(visited));
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(!visited[i] && graph[i].size() > 0){
            dfs(i);
            cnt++;
        }
    }

    if(cnt > 0)
        cnt--;

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}
