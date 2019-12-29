/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 998244353
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX*10], fact[MAX*10];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n;

    dp[1] = 1;

    fact[0] = fact[1] = 1;
    for(int i = 1; i <= n; i++)
    	fact[i] = (i * fact[i-1]) % MOD;

    for(int i = 2; i <= n; i++){
    	dp[i] = ((dp[i-1] + fact[i-1] - 1 + MOD) * i) % MOD;
    }

    cout<<dp[n]<<endl;

    return 0;
}
