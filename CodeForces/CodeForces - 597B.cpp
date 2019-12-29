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
#define MAX 500005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, start[MAX], dp[MAX];
ii arr[MAX];

int solve(int pos)
{
    if(pos >= n)
        return 0;
    if(dp[pos] != -1)
        return dp[pos];

    int ret = 0;
    int x = upper_bound(start, start + n, arr[pos].ss) - start;
    ret = max(ret, 1 + solve(x));
    ret = max(ret, solve(pos + 1));

    return dp[pos] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i].ff>>arr[i].ss;
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++)
        start[i] = arr[i].ff;


    memset(dp, -1, sizeof(dp));

    int res = solve(0);

    cout<<res<<endl;

    return 0;
}
