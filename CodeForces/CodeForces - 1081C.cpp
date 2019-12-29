//Problem ID: CodeForces - 1081C (Colourful Bricks)
//Programmer: IQBAL HOSSIAN     Description: DP/Combinatorics
//Date: 12/04/19
#include <bits/stdc++.h>
#define MAX 2005
#define MOD 998244353
using namespace std;

typedef long long ll;
int n, m, k;
int dp[MAX][MAX];

ll solve(int pos, int cnt)
{
    if(pos >= n){
        if(cnt == k)
            return 1;
        return 0;
    }
    if(dp[pos][cnt] != -1)
        return dp[pos][cnt];

    ll ret = 0;
    if(pos == 0){
        ret = ret + (m * solve(pos + 1, cnt)) % MOD;
    }
    else{
        ret = (ret + solve(pos + 1, cnt)) % MOD;
        if(cnt < k){
            ret = (ret + ((m - 1) * solve(pos + 1, cnt + 1)) % MOD) % MOD;
        }
    }

    return dp[pos][cnt] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;

    memset(dp, -1, sizeof(dp));
    ll result = solve(0, 0);

    cout<<result<<endl;

    return 0;
}
