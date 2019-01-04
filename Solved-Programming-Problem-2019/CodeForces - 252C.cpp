//Problem ID: CodeForces 252C (Points on line)
//Programmer: IQBAL HOSSAIN     Description: Binary Search, Combinatorics
//Date: 02/01/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll solve(ll prev, ll curr, int idx)
{
    //cout<<prev<<" "<<curr<<" "<<idx<<endl;
    ll ans = 0;
    if(idx > prev || (3 - idx) > curr)
        return ans;
    if(idx == 2){
        ans += (((prev * (prev - 1)) / 2) * curr);
    }
    else if(idx == 1){
        ans += (prev * ((curr * (curr - 1)) / 2));
    }
    else if(idx == 0){
        ans += (curr * (curr - 1) * (curr - 2))/6;
    }

    //cout<<ans<<endl;
    return ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, d, arr[MAX], visited[MAX] = {0};
	ll ans = 0;

	cin>>n>>d;

	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

    int idx = lower_bound(arr, arr+n, arr[0] + d) - arr;
    if(!binary_search(arr, arr+n, arr[0]+d))
        idx--;
    if(idx >= 2){
        ans += (ll) ((ll) idx * (idx - 1) * (idx + 1)) / 6;
    }
    //cout<<idx<<endl;
    int prevIdx = idx;
	for(int i = 1; i < n - 2; i++){
		idx = lower_bound(arr, arr + n, arr[i] + d) - arr;
		if(!binary_search(arr, arr+n, arr[i] + d)){
            idx--;
		}
		int temp = idx - prevIdx;
		int prev = prevIdx - i + 1;
		for(int j = 2; j >= 0; j--){
            ans += solve((ll) prev, (ll) temp, j);
		}
		prevIdx = idx;
	}

	cout<<ans<<endl;

	return 0;
}
