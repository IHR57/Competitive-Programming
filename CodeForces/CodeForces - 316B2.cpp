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
#define MAX 1005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int x, par[MAX], vis[MAX], pos, cnt;
bool foundPos;
vector<int> graph[MAX];
int dp[MAX];

void dfs(int u)
{
    vis[u] = 1;
    if(u == x){
        foundPos = true;
        pos = cnt;
    }
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!vis[v]){
            cnt++;
            dfs(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n>>x;

    for(int i = 1; i <= n; i++){
        cin>>par[i];
        if(par[i] != 0)
            graph[par[i]].pb(i);
    }

    vector<int> v;

    for(int i = 1; i <= n; i++){
        if(!vis[i] && par[i] == 0){
            cnt = 1;
            foundPos = false;
            dfs(i);
            if(!foundPos){
                v.pb(cnt);
            }
        }
    }

    dp[pos] = 1;
    for(int j = 0; j < v.size(); j++){
        for(int i = n; i >= 1; i--){
            if(i >= v[j] && dp[i-v[j]])
                dp[i] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        if(dp[i]){
            cout<<i<<endl;
        }
    }
    return 0;
}
