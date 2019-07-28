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

vector<int> graph[MAX];
int n, color[MAX], src, newSrc, root;
set<int> st;
void dfs(int u, int par)
{
	for(int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i];
		if(v == root || v == par)
			continue;
		if(color[v] != color[src]){
			newSrc = v;
		}
		dfs(v, u);
	}
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int u, v;

    cin>>n;

    for(int i = 0; i < n - 1; i++){
    	cin>>u>>v;
    	graph[u].pb(v);
    	graph[v].pb(u);
    }

    for(int i = 1; i <= n; i++){
    	cin>>color[i];
    }

    int r1 = -1, r2 = -1;

    for(int i = 1; i <= n; i++){
    	for(int j = 0; j < graph[i].size(); j++){
    		v = graph[i][j];
    		if(color[i] != color[v]){
    			r1 = i;
    			r2 = v;
    		}
    	}
    }
    if(r1 == -1){
    	cout<<"YES"<<endl;
    	cout<<1<<endl;
    	return 0;
    }
    root = r1;
    for(int i = 0; i < graph[r1].size(); i++){
    	v = graph[r1][i];
    	src = v;
    	newSrc = -1;
    	dfs(v, -1);
    	if(newSrc != -1)
    		break;
    }
    if(newSrc == -1){
    	cout<<"YES"<<endl;
    	cout<<r1<<endl;
    	return 0;
    }

    root = r2;
    for(int i = 0; i < graph[r2].size(); i++){
    	v = graph[r2][i];
    	src = v;
    	newSrc = -1;
    	dfs(v, -1);
    	if(newSrc != -1)
    		break;
    }

    if(newSrc == -1){
    	cout<<"YES"<<endl;
    	cout<<r2<<endl;
    	return 0;
    }

    cout<<"NO"<<endl;

    return 0;
}