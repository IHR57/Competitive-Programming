#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
ll arr[MAX];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin>>n>>k;

	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	ll curr = (k * 1LL * 2);
	int lidx = 0;

	sort(arr, arr + n);
	int res = 0;
	for(int i = 0; i < n; i++){
		while(arr[i] > curr){
			curr = (curr << 1);
			res++;
		}
		curr = max(curr, (arr[i] << 1));
	}

	cout<<res<<endl;

	return 0;
}