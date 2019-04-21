//Problem ID: LightOJ - 1201 (A Perfect Murder)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (DP on Tree)
//Date: 16/04/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

vector<int> graph[MAX];
int dp[2][MAX];
int arr[MAX];

void dfs(int u, int parent)
{
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(parent == v)
            continue;
        dfs(v, u);
    }

    int taken = 1, not_taken = 0;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        taken += dp[1][v];
        not_taken += dp[0][v];
    }

    dp[1][u] = not_taken;
    dp[0][u] = max(taken, not_taken);
}

int main()
{
    int test, caseno = 1, n, m;
    int u, v;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &u,  &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        memset(dp, 0, sizeof(dp));
        int result = 0;
        for(int i = 1; i <= n; i++){
            if(dp[0][i] == 0){
                dfs(i, -1);
                result += dp[0][i];
            }
        }

        printf("Case %d: %d\n", caseno++, result);
        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}
