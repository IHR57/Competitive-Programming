#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
int dp[MAX][2];

void dfs(int u, int parent)
{
    int ret1 = 1, ret2 = 0;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(parent == v)
            continue;
        dfs(v, u);
        ret2 += dp[v][1];
        ret1 += min(dp[v][0], dp[v][1]);
    }

    dp[u][1] = ret1;
    dp[u][0] = ret2;
}

int main()
{
    int n, u, v;

    cin>>n;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1);

    int ans = min(dp[1][0], dp[1][1]);

    cout<<ans<<endl;

    return 0;
}
