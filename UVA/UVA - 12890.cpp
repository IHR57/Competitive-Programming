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
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], pos[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test, n;

    scanf("%d", &test);

    while(test--){
    	scanf("%d", &n);
    	int idx = 1;
    	map<int, int> mp;
    	for(int i = 0; i <  n; i++){
    		scanf("%d", &arr[i]);
    		if(mp[arr[i]]  == 0)
    			mp[arr[i]] = idx++;
    	}

    	memset(pos, -1, sizeof(pos));

    	int Ix = n - 1;
    	ll ans = 0;
    	for(int i = n - 1; i >= 0; i--){
    		int x = pos[mp[arr[i]]];
    		if(x ==  -1 && Ix == n - 1){
    			ans += (ll) (n - i);
    		}
    		else if(x == -1 && Ix != n - 1){
    			ans += (ll) (Ix - i + 1);
    		}
    		else{
    			Ix = min(Ix, x - 1);
    			ans += (ll) (Ix - i + 1);
    		}
    		pos[mp[arr[i]]] = i;
    	}

    	printf("%lld\n", ans);
    }

    return 0;
}
