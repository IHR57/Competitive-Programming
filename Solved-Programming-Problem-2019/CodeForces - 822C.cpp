/*
Template for vjudge contest
	CodeForces ID: The_Silent_Man
	LightOJ ID: 29578
*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<pair<ii, ii> >v;
ll dp[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, x, l, r, c;
    cin>>n>>x;

    for(int i = 0; i < n; i++){
    	cin>>l>>r>>c;
    	v.pb(mp(mp(l, -1), mp(r, c)));
    	v.pb(mp(mp(r, 1), mp(l, c)));
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < MAX; i++)
    	dp[i] = 1e15;

    ll ans = 1e15;
    for(int i = 0; i < v.size(); i++){
    	if(v[i].ff.ss == -1){
    		int len = v[i].ss.ff - v[i].ff.ff + 1;
    		if(len <= x){
    			ans = min(ans, v[i].ss.ss + dp[x - len]);
    		}
    	}
    	else{
    		int len = v[i].ff.ff - v[i].ss.ff + 1;
    		dp[len] = min(dp[len], (ll) v[i].ss.ss);
    	}
    }

    if(ans >= 1e15){
    	cout<<"-1"<<endl;
    }
    else{
    	cout<<ans<<endl;
    }

    return 0;
}
