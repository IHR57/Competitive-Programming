//Problem ID: SPOJ - STONE2 (A Famous Stone Collector)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 28/06/19
//Problem Link: https://www.spoj.com/problems/STONE2/
#include <bits/stdc++.h>
#define MAX 11005
#define EPS 1e-8
#define MOD 1000000007
using namespace std;

typedef long long ll;
ll freq[MAX], tfreq[MAX], arr[105];
ll dp[105], fact[MAX], inv[MAX];

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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    fact[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = (i * fact[i-1]) % MOD;
        inv[i] = bigMod(fact[i], MOD - 2);
    }
    int n, caseno = 1;

    while(scanf("%d", &n) == 1){
        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < n; i++){
            scanf("%lld", &arr[i]);
        }
        dp[0] = arr[0];
        for(int i = 1; i <= arr[0]; i++)
            freq[i] = 1;

        for(int i = 1; i < n; i++){
            dp[i] = 0;
            for(int j = 1; j <= arr[i]; j++){
                for(int k = 1; k < MAX; k++){
                    if(!freq[k])
                        break;
                    ll temp = (((freq[k] * fact[j+k]) % MOD * inv[j]) % MOD * inv[k]) % MOD;
                    tfreq[j+k] = (tfreq[j+k] + temp) % MOD;
                    //cout<<temp<<endl;
                    dp[i] = (dp[i] + temp) % MOD;
                }
                tfreq[j] = (tfreq[j] + 1) % MOD;
            }
            dp[i] = (dp[i] + dp[i-1]) % MOD;
            dp[i] = (dp[i] + arr[i]) % MOD;
            for(int j = 1; j < MAX; j++){
                if(tfreq[j]){
                    freq[j] = (freq[j] + tfreq[j]) % MOD;
                }
                tfreq[j] = 0;
            }
            dp[i] %= MOD;
        }

        printf("Case %d: %lld\n", caseno++, dp[n-1]);
    }

    return 0;
}