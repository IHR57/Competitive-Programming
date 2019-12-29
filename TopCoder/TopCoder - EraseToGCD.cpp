/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
//Date: 10/09/19
//Description: DP
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
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[505][1005];
int n, k, arr[505];

class EraseToGCD
{
	public:
		int solve(int pos, int rem)
		{
			if(pos >= n){
				if(rem == k)
					return 1;
				return 0;
			}
			if(dp[pos][rem] != -1)
				return dp[pos][rem];
			int ret = 0;
			ret += solve(pos + 1, __gcd(rem, arr[pos])) % MOD;
			ret += solve(pos + 1, rem) % MOD;

			return dp[pos][rem] = ret % MOD;
		}
		int countWays(vector<int> s, int goal)
		{
			n = s.size(), k = goal;
			for(int i = 0; i < s.size(); i++)
				arr[i] = s[i];
			memset(dp, -1, sizeof(dp));
			int res = solve(0, 0);
			return res;
		}
};

// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     #ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
//     	freopen("output.txt", "w", stdout);
//     #endif
//     cin>>n>>k;
//     vector<int> v;
//     for(int i = 0; i < n ; i++){
//     	cin>>arr[i];
//     	v.pb(arr[i]);
//     }

//     EraseToGCD obj = EraseToGCD();
//     cout<<obj.countWays(v, k)<<endl;

//     return 0;
// }
