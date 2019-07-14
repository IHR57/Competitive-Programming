#include <bits/stdc++.h>
#define MAX 11005
#define EPS 1e-8
#define MOD 1000000007
using namespace std;

typedef long long ll;
ll dp[105][MAX], fact[MAX], inv[MAX], arr[105];
int visited[105][MAX], n;

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b / 2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;
    return x;
}

ll solve(int pos, int tot)
{
    if(pos >= n){
        if(tot)
            return fact[tot];
        return 0;
    }
    if(visited[pos][tot])
        return dp[pos][tot];
    visited[pos][tot] = 1;
    ll ret = 0;
    for(int i = 0; i <= arr[pos]; i++){
        ret = (ret + (solve(pos + 1, tot + i) * inv[i]) % MOD) % MOD;
    }

    return dp[pos][tot] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    fact[0] = inv[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = (i * fact[i-1]) % MOD;
        inv[i] = bigMod(fact[i], MOD - 2);
    }
    int caseno = 1;

    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; i++){
            scanf("%lld", &arr[i]);
        }
        memset(visited, 0, sizeof(visited));
        printf("Case %d: %lld\n", caseno++, solve(0, 0));
    }

    return 0;
}