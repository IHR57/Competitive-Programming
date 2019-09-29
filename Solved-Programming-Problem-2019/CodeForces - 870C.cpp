#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> dp(16, -1);

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int q, n;
    int c[3] = {4, 6, 9};
    dp[0] = 0;
    for(int i = 1; i < 16; i++){
        for(int j = 0; j < 3; j++){
            if(i - c[j] >= 0 && dp[i-c[j]] != -1)
                dp[i] = max(dp[i], dp[i-c[j]] + 1);
        }
    }

    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>n;
        if(n < 16){
            cout<<dp[n]<<endl;
            continue;
        }
        int ans = (n - 16) / 4 + 1;
        ans += dp[n-4*ans];
        cout<<ans<<endl;
    }

    return 0;
}
