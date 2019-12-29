//Problem ID: SPOJ - CHAIR (Chairs)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 28/03/19
//Problem Link: https://www.spoj.com/problems/CHAIR/
#include <bits/stdc++.h>
#define MAX 1005
#define MOD 1000000003
using namespace std;

typedef long long ll;

ll dp[MAX][MAX];
int n, k;

ll solve(int pos, int cnt)
{
    if(pos >= n){
        if(cnt == k)
            return 1;
        return 0;
    }
    if(dp[pos][cnt] != -1)
        return dp[pos][cnt];

    ll ret1 = 0, ret2 = 0;
    ret1 = solve(pos + 1, cnt) % MOD;
    ret2 = solve(pos + 2, cnt + 1) % MOD;

    return dp[pos][cnt] = (ret1 + ret2) % MOD;

}
int main()
{
    scanf("%d %d", &n, &k);

    memset(dp, -1, sizeof(dp));
    ll result1 = solve(1, 0);

    n--;
    memset(dp, -1, sizeof(dp));
    ll result2 = solve(0, 0);

    memset(dp, -1, sizeof(dp));
    ll result3 = solve(1, 0);

    ll res = ((result1 + result2) % MOD - result3) % MOD;
    if(res < 0)
        res += MOD;

    printf("%lld\n", res);

    return 0;
}
