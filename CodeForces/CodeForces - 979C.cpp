//Problem ID: CodeForces - 979C (Kuro and Walking Route)
//Programmer: IQBAL HOSSAIN     Description: DFS
//Date: 26/04/19
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

typedef long long ll;

vector<int> graph[MAX];
int cnt;
int visited[MAX], parent[MAX];

void dfs(int u)
{
    visited[u] = 1;
    cnt++;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int u, v, n, f, b;

    cin>>n>>f>>b;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(parent, -1, sizeof(parent));
    memset(visited, 0, sizeof(visited));
    dfs(f);

    memset(visited, 0, sizeof(visited));
    for(int i = b; i != -1; i =  parent[i]){
        //cout<<i<<" "<<endl;
        visited[i] = 1;
    }

    ll ans = 1;

    cnt = 0;
    dfs(f);
    ans = (ans * 1LL * cnt);

    cnt = 0;
    dfs(b);
    ans = (ans * 1LL * cnt);

    ll res = (1LL * n * (n - 1)) - ans;

    cout<<res<<endl;

    return 0;
}
