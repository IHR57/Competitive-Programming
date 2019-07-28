//Problem ID: TIMUS - 1017 (Staircases)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 18/07/19
#include <bits/stdc++.h>
#define MAX 505
#define MOD 1000000007
using namespace std;

typedef long long ll;
ll dp[MAX][MAX], cs[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;

    scanf("%d", &n);
    
    dp[3][1] = 1, dp[4][1] = 1, dp[5][1] = 1, dp[5][2] = 1;
    cs[3][1] = cs[4][1] = cs[5][1] = 1;
    cs[5][2] = 2;

    for(int i = 6; i <= n; i++){
        int k = (i + 1) / 2 - 1;
        for(int j = 1; j <= k; j++){
            int temp = i - j;
            int tx = (temp + 1) / 2 - 1;
            if(tx <= j)
                dp[i][j] = 1;
            else
                dp[i][j] = 1 + (cs[temp][(temp + 1) / 2 - 1] - cs[temp][j]);
            cs[i][j] = cs[i][j-1] + dp[i][j];
        }
    }

    printf("%lld\n", cs[n][(n + 1) / 2 - 1]);

    return 0;
}