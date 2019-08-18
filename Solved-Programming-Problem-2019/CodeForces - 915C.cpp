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
#define MAX 100005
using namespace std;

typedef unsigned long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

set<int> s;
int cnt[10];
//string a, b;

ll a, b;
/*
vector<int> digit;
ll dp[(1<<20)];
int n;

ll solve(int mask)
{
    if(mask == (1<<n) - 1){     //we've taken all the element
        return 0;
    }

    if(dp[mask] != -1)
        return dp[mask];

    ll Min = 1e18;

    ll ret = 0;
    string ans = "";
    for(int i = 0; i < n; i++){
        if(!check(mask, i)){            //if the i'th bit is not set i.e 0
            ret = ((ret * 10) + digit[i]) + solve(Set(mask, i));
        	ans += digit[i] + 48;
        }
    }
    dp[mask] = ret;

    return dp[mask];
}
*/

ll p[21], ans = -1;

void solve(int n, ll val)
{
	if(n < 0){
		cout<<val<<endl;
		exit(0);
	}
	for(int i = 9; i >= 0; i--){
		if(cnt[i] > 0 && val + (i * 1LL * p[n]) <= b){
			cnt[i]--;
			solve(n - 1, val + (i * 1LL * p[n]));
			cnt[i]++;
		}
	}
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int n = 0;
    cin>>a>>b;
    //memset(dp, -1, sizeof(dp));
    while(a){
    	cnt[a%10]++;
    	a /= 10;
    	n++;
    }

    p[0] = 1;
    for(int i = 1; i < 19; i++)
    	p[i] = p[i-1] * 1LL * 10;

    solve(n - 1, 0);

    cout<<ans<<endl;

    return 0;

}
