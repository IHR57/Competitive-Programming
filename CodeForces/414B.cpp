#include <bits/stdc++.h>
#define MAX 2005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll dp[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k;

    cin>>n>>k;

    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= n; j++)
            dp[i][j] = 0;
    }

    for(int i = 0; i <= n; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= k; i++){
        for(int j = 1; j <= n; j++){
            for(int l = j; l <= n; l += j){
                dp[i][l] = (dp[i][l] + dp[i-1][j]) % MOD;
            }
        }
    }

    ll sum = 0;

    for(int i = 1; i <= n; i++){
        sum = (sum + dp[k][i]) % MOD;
    }

    cout<<sum % MOD<<endl;
}
