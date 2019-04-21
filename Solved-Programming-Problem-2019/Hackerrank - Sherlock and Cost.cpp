//Problem ID: HackerRank - Sherlock and Cost
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 17/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int dp[MAX][105], n, arr[MAX];

int solve(int pos, int num)
{
    if(pos >= n)
        return 0;
    if(dp[pos][num] != -1)
        return dp[pos][num];

    int ret = 0;
    if(pos + 1 <= n - 1){
        ret = max(ret, abs(1 - num) + solve(pos + 1, 1));
        ret = max(ret, abs(arr[pos+1] - num) + solve(pos + 1, arr[pos+1]));
    }
    return dp[pos][num] = ret;
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int Max = 0;
        memset(dp, -1, sizeof(dp));
        Max = max(solve(0, 1), solve(0, arr[0]));

        printf("%d\n", Max);
    }

    return 0;
}
