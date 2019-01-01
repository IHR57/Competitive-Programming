#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
int visited[MAX] = {0}, cats[MAX], ans = 0, m;

void dfs(int u, int cat)
{
    int sum = 0;
    visited[u] = 1;
    if(cat > m)
        return;
    bool flag = false;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            if(cats[v])
                sum = cat + 1;
            else
                sum = 0;
            dfs(v, sum);
            flag = true;
        }
    }
    if(!flag)
        ans++;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u, v;

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        cin>>cats[i];
    }

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //parent[1] = -1;     //1 is a root node
    dfs(1, cats[1]);

    cout<<ans<<endl;

    return 0;
}
