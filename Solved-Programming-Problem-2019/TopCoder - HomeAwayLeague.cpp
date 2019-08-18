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
#define MAX 500005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll fact[MAX], d[MAX];

class HomeAwayLeague
{
	public:
		ll powMod(ll a, ll b)
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
		int matches(int n)
		{
			fact[0] = 1;
			for(int i = 1; i <= n; i++)
				fact[i] = (i * fact[i-1]) % MOD;
			d[1] = 0, d[2] = 1;
			for(int i = 3; i <= n; i++)
				d[i] = ((d[i-1] + d[i-2]) % MOD * (i - 1)) % MOD;
			ll ans = 1;
			ans *= (fact[n] * powMod(fact[n/2], MOD - 2)) % MOD;
			ans = (ans * d[n/2]) % MOD;
			return (int) ans;
		}
};
// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     #ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
//     	freopen("output.txt", "w", stdout);
//     #endif
//     HomeAwayLeague obj = HomeAwayLeague();
//     cout<<obj.matches(8)<<endl;

//     return 0;
// }
