#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef pair<int, int> pii;
int dp[MAX], visited[MAX];
vector<pii> graph[MAX];

void dfs(int u)
{
    visited[u] = 1;
    int Max = 0;

    for(int i = 0; i < graph[u].size(); i++){
        pii v = graph[u][i];
        if(!visited[v.first]){
            dp[v.first] = dp[u] + v.second;
            dfs(v.first);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u, v, w;

    cin>>n;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    dfs(0);

    cout<<*max_element(dp, dp + n)<<endl;

    return 0;
}
