/*
Template for vjudge contest
	CodeForces ID: The_Silent_Man
	LightOJ ID: 29578
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

int p[MAX], a[MAX], pos[MAX];
int ans[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, l, r;

    cin>>n>>l>>r;

    for(int i = 0; i < n ; i++){
    	cin>>a[i];
    }
    for(int i = 0; i < n; i++){
    	cin>>p[i];
    	pos[p[i]] = i;
    }

    int prev = l - a[pos[1]];
    ans[pos[1]] = l;

    for(int i = 2; i <= n; i++){
    	int low = l, high = r, mid, res = -1;
    	while(low <= high){
    		mid = (low + high + 1) >> 1;
    		if((mid - a[pos[i]]) > prev){
    			res = mid;
    			high = mid - 1;
    		}
    		else{
    			low = mid + 1;
    		}
    	}
    	if(res == -1){
    		cout<<"-1"<<endl;
    		return 0;
    	}
    	prev = res - a[pos[i]];
    	ans[pos[i]] = res;
    }

    for(int i = 0; i < n; i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
