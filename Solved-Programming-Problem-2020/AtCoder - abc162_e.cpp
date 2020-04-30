//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX];

ll powmod(ll a, ll b)
{
    ll res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    ll sum = 0;
    for(int i = k; i >= 1; i--){
        int rem = k / i;
        ll temp = powmod(rem, n) % MOD;
        ll gSum = 0;
        for(int j = i * 2; j <= k; j += i){
            gSum = (gSum + dp[j]) % MOD;
        }
        dp[i] = (temp - gSum + MOD) % MOD;
    }

    ll ans = 0;
    for(int i = 1; i <= k; i++){
        ans = (ans + (dp[i] * i) % MOD) % MOD;
    }

    cout<<ans<<endl;

    return 0;
}
