//Problem ID: HackerRank - Knapsack
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 17/05/19
//Problem Link: https://www.hackerrank.com/challenges/unbounded-knapsack/problem
#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

int arr[MAX];
int dp[MAX][MAX], vis[MAX];
int n, k;

int solve(int pos, int tot)
{
    vis[tot] = 1;
    if(pos >= n){
        return 1;
    }
    if(dp[pos][tot] != -1)
        return dp[pos][tot];

    int ret1 = 0, ret2 = 0;
    if(tot + arr[pos] <= k){
        ret1 = solve(pos, tot + arr[pos]);
    }
    ret2 = solve(pos + 1, tot);

    return dp[pos][tot] = ret1 | ret2;
}

int main()
{
    int test;
    scanf("%d", &test);

    while(test--){
        scanf("%d %d",  &n, &k);
        memset(vis, 0, sizeof(vis));
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int res = solve(0, 0);

        int ans = -1;
        for(int i = k; i >= 1; i--){
            if(vis[i]){
                ans = i;
                break;
            }
        }

        if(ans != -1){
            printf("%d\n", ans);
        }
        else{
            printf("0\n");
        }
    }

    return 0;
}
