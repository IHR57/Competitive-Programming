//Problem ID: HackerRank - Play on Benders
//Programmer: IQBAL HOSSAIN     Description: Game Theory (Grundy Numbers)
//Date: 14/05/19
//Problem Link: https://www.hackerrank.com/challenges/benders-play/problem
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int dp[MAX];
vector<int> graph[MAX];

int dfs(int u)
{
    if(graph[u].size() == 0)
        return 0;
    if(dp[u] != -1)
        return dp[u];
    set<int> s;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        int g = dfs(v);
        s.insert(g);
    }
    int ret = 0;
    while(s.find(ret) != s.end())
        ret++;
    return dp[u] = ret;
}

int main()
{
    int n, m, u, v, q, k, val;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }

    memset(dp, -1, sizeof(dp));

    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &k);
        int ans = 0;
        for(int j = 0; j < k; j++){
            scanf("%d", &val);
            ans ^= dfs(val);
        }
        (ans) ? printf("Bumi\n") : printf("Iroh\n");
    }

    return 0;
}
