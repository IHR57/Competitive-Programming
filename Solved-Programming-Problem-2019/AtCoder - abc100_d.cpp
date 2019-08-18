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
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll arr[1005][3];

vector<ll> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, m;

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
    	for(int j = 0; j < 3; j++){
    		cin>>arr[i][j];
    	}
    }

    ll res = 0;
    for(int k = 0; k < 8; k++){
    	v.clear();
    	for(int i = 1; i <= n; i++){
    		ll temp = 0;
    		for(int j = 0; j < 3; j++){
    			if((k / (1 << j)) % 2 == 0)
    				temp += arr[i][j];
    			else
    				temp -= arr[i][j];
    		}
    		v.pb(temp);
    	}
    	sort(v.begin(), v.end());
    	reverse(v.begin(), v.end());
    	ll sum = 0;
    	for(int i = 0; i < m; i++){
    		sum += v[i];
    	}
    	res = max(res, sum);
    }

    cout<<res<<endl;

    return 0;
}
