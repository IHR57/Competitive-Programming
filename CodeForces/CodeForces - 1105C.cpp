#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX][3];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, l, r;
    ll c[3] = {0};

    cin>>n>>l>>r;
    
    if(r - l <= 10){
        for(int i = l; i <= r; i++){
            c[i%3]++;
        }
    }
    else{
        int idx;
        for(int i = r; ; i--){
            c[i%3]++;
            idx = r;
            if(l % 3 == i % 3)
                break;
        }
        c[0] += (r - l) / 3, c[1] += (r - l) / 3, c[2] += (r - l) / 3;
    }
    // cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
    dp[1][0] = c[0], dp[1][1] = c[1], dp[1][2] = c[2];
    for(int i = 2; i <= n; i++){
        dp[i][0] += (((dp[i-1][0] * c[0]) % MOD + (dp[i-1][1] * c[2]) % MOD) % MOD + (dp[i-1][2] * c[1]) % MOD) % MOD;
        dp[i][1] += (((dp[i-1][0] * c[1]) % MOD + (dp[i-1][1] * c[0]) % MOD) % MOD + (dp[i-1][2] * c[2]) % MOD) % MOD;
        dp[i][2] += (((dp[i-1][0] * c[2]) % MOD + (dp[i-1][1] * c[1]) % MOD) % MOD + (dp[i-1][2] * c[0]) % MOD) % MOD;
    }

    cout<<dp[n][0]<<endl;

    return 0;
}
