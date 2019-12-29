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

vector<pair<int, int> > v[105];
int vis[105], idx[105];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, m, x, y;

    cin>>n>>m;

    int u = 1, r = 1, k = 1;

    for(int i = 0; i < m; i++){
    	cin>>x>>y;
    	if(!vis[x]){
    		vis[x] = 1;
    		idx[x] = k++;
    		r++;
    	}
    	if(!vis[y]){
    		vis[y] = 1;
    		idx[y] = k++;
    		r++;
    	}
    	v[x].pb(mk(idx[x], u));
    	v[y].pb(mk(idx[y], u));
    	u++;
    }

    u = 100000, r = 100000;
    for(int i = 1; i <= n; i++){
    	if(v[i].size() == 0){
    		cout<<1<<endl;
    		cout<<u<<" "<<r<<endl;
    		u++, r++;
    	}
    	else{
	    	cout<<v[i].size()<<endl;
	    	for(int j = 0; j < v[i].size(); j++){
	    		cout<<v[i][j].ff<<" "<<v[i][j].ss<<endl;
	    	}
	    }
    }

    return 0;
}
