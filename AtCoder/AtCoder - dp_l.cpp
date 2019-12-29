/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
//Problem Link: https://atcoder.jp/contests/dp/tasks
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
#define MAX 3005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX][MAX][2];
ll arr[MAX];
int n;

ll solve(int i, int j, int x)
{
    if(i > j)
        return 0;
    if(dp[i][j][x] != -1)
        return dp[i][j][x];
    ll ret = 0;
    if(x == 0){
        ret = arr[i] + solve(i + 1, j, !x);
        ret = max(ret, arr[j] + solve(i, j - 1, !x));
    }
    else{
        ret = solve(i + 1, j, !x) - arr[i];
        ret = min(ret, solve(i, j - 1, !x) - arr[j]);
    }

    return dp[i][j][x] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    memset(dp, -1, sizeof(dp));
    ll result = solve(0, n - 1, 0);

    cout<<result<<endl;

    return 0;
}
