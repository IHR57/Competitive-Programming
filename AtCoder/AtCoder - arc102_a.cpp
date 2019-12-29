//Problem ID: AtCoder - arc102_a (Triangular Relationship)
//Programmer: IQBAL HOSSAIN 	Description: Combinatorics
//Date: 24/07/19
//Problem Link: https://atcoder.jp/contests/abc108/tasks/arc102_a
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n, k;

	cin>>n>>k;

	ll res = (ll) (n / k);
	ll ans = 0;

	ans += res;
	ans += ((res * (res - 1)) / 2) * 6;
	ans += ((res * (res - 1) * (res - 2)) / 6) * 6;

	if(k % 2 == 0){
		res = n / (k / 2) - res;
		ans += res;
		ans += ((res * (res - 1)) / 2) * 6;
		ans += ((res * (res - 1) * (res - 2)) / 6) * 6;
	}

	cout<<ans<<endl;

	return 0;
}