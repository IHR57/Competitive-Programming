/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
//Date: 10/09/19
//Category: Divide and Conquer
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

int arr[MAX];
int n, k, a, b, maxLevel;

ll solve(int low, int high){
	if(low > high)
		return 0;
	int mid = (low + high) >> 1;
	int cs = upper_bound(arr, arr + k, high) - arr;
	cs -= lower_bound(arr, arr + k, low) - arr;
	ll ans = 1LL * (high - low + 1) * b * cs;
	if(cs == 0){
		return a;
	}
	if(low == high){
		return ans;
	}
	return min(ans, solve(low, mid) + solve(mid + 1, high));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin>>n>>k>>a>>b;
    for(int i = 0; i < k; i++){
    	cin>>arr[i];
    }
    sort(arr, arr + k);
    int low = 1, high = (1 << n);

    ll res = solve(low, high);

    cout<<res<<endl;

    return 0;
}
