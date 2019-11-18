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
#define MAX 1000005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int k;
int dp[MAX];

string str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int s;

    cin>>k;
    cin>>str;

    int n = str.length();
    ll ans = 0;

    s = 0;

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        s += (str[i] - 48);
        dp[s]++;
    }

    for(int i = k; i <= s; i++){
        if(k == 0){
            ans += 1LL * (dp[i] - 1) * dp[i] / 2;
        }
        else{
            ans += (1LL * dp[i] * dp[i-k]);
        }
    }

    cout<<ans<<endl;

    return 0;
}
