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
#define MOD 1000000007
#define MAX 15
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dp[15][205][1005];
int a[MAX], b[MAX], c[MAX], d[MAX];
int n, m, c0, d0;

int solve(int pos, int stuffing, int dough)
{
    if(pos >= m){
        return 0;
    }
    if(dp[pos][stuffing][dough] != -1)
        return dp[pos][stuffing][dough];

    int ret = 0;
    if(stuffing + b[pos] <= a[pos] && dough + c[pos] <= n){
        ret = max(ret, d[pos] + solve(pos, stuffing+b[pos], dough + c[pos]));
        ret = max(ret, d[pos] + solve(pos + 1, 0, dough+c[pos]));
    }
    if(dough + c0 <= n){
        ret = max(ret, d0 + solve(pos, stuffing, dough + c0));
        ret = max(ret, d0 + solve(pos + 1, stuffing, dough + c0));
    }
    ret = max(ret, solve(pos + 1, 0, dough));

    return dp[pos][stuffing][dough] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>m>>c0>>d0;

    for(int i = 0; i < m; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    memset(dp, -1, sizeof(dp));

    int res = solve(0, 0, 0);

    cout<<res<<endl;

    return 0;
}
