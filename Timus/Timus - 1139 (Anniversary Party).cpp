//Problem ID: TIMUS - 1139 (Anniversary Party)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 16/04/19
#include <bits/stdc++.h>
#define MAX 6005
using namespace std;

int dp[MAX][2], arr[MAX];
vector<int> graph[MAX];

void dfs(int u, int par)
{
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par){
            continue;
        }
        dfs(v, u);
    }
    int taken = arr[u], not_taken = 0;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        taken += dp[v][1];
        not_taken += dp[v][0];
    }

    dp[u][1] = not_taken;
    dp[u][0] = max(taken, not_taken);
}
int main()
{
    int n, u, v;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d",  &arr[i]);
    }

    while(scanf("%d %d", &u, &v) == 2){
        if(!u && !v)
            break;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1);

    printf("%d\n", dp[1][0]);

    return 0;
}
