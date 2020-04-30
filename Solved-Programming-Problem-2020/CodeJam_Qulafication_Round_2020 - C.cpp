//Date: 04/04/2020
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
#define MAX 105
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 	#ifndef ONLINE_JUDGE
 		freopen("input.txt", "r", stdin);
 		freopen("output.txt", "w", stdout);
 	#endif

 	int test, caseno = 1, n;
 	
 	cin>>test;

 	while(test--){
 		cin>>n;
 		int u, v;
 		vector<pair<ii, int> > vp;
 		vector<int> ans(n + 1, 0);

 		for(int i = 0; i < n; i++){
 			cin>>u>>v;
 			vp.pb(mk(mk(u, v), i));
 		}

 		sort(vp.begin(), vp.end());

 		ans[vp[0].ss] = 1;
 		int idx = 0;

 		while(true){
 			idx = lower_bound(vp.begin(), vp.end(), mk(mk(vp[idx].ff.ss, 0), 0)) - vp.begin();
 			if(idx >= n)
 				break;
 			ans[vp[idx].ss] = 1;
 		}

 		int prev = -1;

 		bool flag = true;
 		for(int i = 0; i < vp.size(); i++){
 			if(ans[vp[i].ss] != 1){
 				if(vp[i].ff.ff >= prev){
 					prev = vp[i].ff.ss;
 					ans[vp[i].ss] = 2;
 				}
 				else{
 					flag = false;
 					break;
 				}
 			}
 		}

 		cout<<"Case #"<<caseno++<<": ";

 		if(!flag)
 			cout<<"IMPOSSIBLE"<<endl;
 		else{
 			for(int i = 0; i < n; i++){
 				(ans[i] == 1) ? cout<<"C" : cout<<"J";
 			}
 			cout<<endl;
 		}

 	}
 	
 
    return 0;
}