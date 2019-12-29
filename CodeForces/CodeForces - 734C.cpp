/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

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

typedef long long ll;
typedef pair<ll, ll> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, m, k;
ll x, s;
ll a[MAX], b[MAX], c[MAX], d[MAX], dp[MAX], temp[MAX];
vector<ii> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin>>n>>m>>k;
    cin>>x>>s;

    ll ans = (n * x);

    for(int i = 0; i < m ; i++){
        cin>>a[i];
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }

    for(int i = 0; i < m ; i++){
        v.pb(mp(b[i], a[i]));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(i){
            dp[i] = min(dp[i-1], v[i].ss);
        }
        else
            dp[i] = v[i].ss;
        temp[i] = v[i].ff;
    }

    for(int i = 0; i < k; i++)
        cin>>c[i];
    for(int i = 0; i < k; i++)
        cin>>d[i];

    c[k] = 0, d[k] = 0, k++;
    for(int i = 0; i < k; i++){
        if(d[i] > s)
            continue;
        if(n - c[i] <= 0){
            ans = 0;
            break;
        }
        else{
            ll t1 = n - c[i], t2 = s - d[i];
            int idx = upper_bound(temp, temp + m, t2) - temp;
            idx--;
            if(idx < 0){
                ans = min(ans, t1 * x);
                continue;
            }
            ans = min(ans, min((t1 * dp[idx]), (t1 * x)));
        }
    }

    cout<<ans<<endl;

    return 0;
}
