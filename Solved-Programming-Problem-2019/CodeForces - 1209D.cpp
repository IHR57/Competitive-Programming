#include <bits/stdc++.h>
#define MAX 200005
#define pb push_back
using namespace std;
 
vector<int> graph[MAX];
int vis[MAX];
 
void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, u, v;
    
    cin>>n>>k;
    
    for(int i = 0; i < k; i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    
    cout<<k - (n - cnt)<<endl;
    
    return 0;
    
}