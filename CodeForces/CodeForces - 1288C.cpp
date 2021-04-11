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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    ll dp[n+m+5][30];

    dp[0][0] = 1;
    for(int i = 1; i < n + m + 5; i++){
        for(int j = 0; j <= min(11, i); j++){
            if(j == 0 || j == i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
            }
        }
    }

    ll ans = 0;
    if(m >= n){
        for(int i = 0; i < n; i++){
            ans = (ans + (dp[m][i] * dp[m+1][n-i-1]) % MOD) % MOD;
        }
    }
    else{
        m--;
        for(int i = 0; i < n; i++){
            //cout<<dp[m+i][m]<<" "<<dp[m+n-i][m+1]<<endl;
            ans = (ans + (dp[m+i][m] * dp[m+n-i][m+1]) % MOD) % MOD;
        }
    }

    cout<<ans % MOD<<endl;

    return 0;
}
