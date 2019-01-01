// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 10005
#define pb push_back
using namespace std;

int color[MAX], visited[MAX], parent[MAX], counter = 0;
vector<int> graph[MAX];

void bfs(int source)
{
    memset(parent, 0, sizeof(parent));
    memset(visited, 0, sizeof(visited));
    visited[source] = 1;

    parent[source] = color[source];
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(parent[u] != color[u]){
                counter++;
                parent[u] = color[u];
        }
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = 1;
                parent[v] = parent[u];
                q.push(v);
            }
        }
    }

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u;

    cin>>n;

    for(int i = 2; i <= n; i++){
        cin>>u;
        graph[i].pb(u);
        graph[u].pb(i);
    }

    for(int i = 1; i <= n; i++){
        cin>>color[i];
    }

    bfs(1);

    cout<<counter+1<<endl;

    return 0;
}
