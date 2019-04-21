//Problem ID: SPOJ - PTO7X (Vertex Cover)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (Vertex Cover)
//Date: 16/04/19
//Problem Link: https://www.spoj.com/problems/PT07X/
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int dp[MAX][2], parent[MAX];
vector<int> graph[MAX];

int dfs(int u, int isPlaced)
{
    if(graph[u].size() == 0)
        return 0;
    if(dp[u][isPlaced] != -1)
        return dp[u][isPlaced];

    int ret = 0;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(parent[u] != v){
            parent[v] = u;
            if(isPlaced)
                ret += min(dfs(v, 0), dfs(v, 1));
            else
                ret += dfs(v, 1);
        }
    }

    dp[u][isPlaced] = ret + isPlaced;

    return dp[u][isPlaced];
}

int main()
{
    int n, u, v;

    scanf("%d",  &n);
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));
    int result = min(dfs(1, 0), dfs(1, 1));

    printf("%d\n", result);

    return 0;
}
