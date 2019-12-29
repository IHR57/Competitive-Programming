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
#define MAX 105
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

bool found;
vector<ii> graph[MAX];
int visited[MAX];

void dfs(int u, int t, int c)
{
    if(u == t){
        found = true;
        return;
    }
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        ii v = graph[u][i];
        if(!visited[v.ff] && v.ss == c){
            dfs(v.ff, t, c);
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
    int n, m, u, v, c, q;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v>>c;
        graph[u].pb(mk(v, c));
        graph[v].pb(mk(u, c));
    }

    cin>>q;

    for(int i = 0; i < q; i++){
        cin>>u>>v;
        int cnt = 0;
        for(int j = 1; j <= m; j++){
            memset(visited, 0, sizeof(visited));
            found = false;
            dfs(u, v, j);
            if(found)
                cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
