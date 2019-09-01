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
#define MAX 10005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> graph[MAX];
int parent[MAX], visited[MAX], sbt[MAX], ans[MAX];

void dfs(int u)
{
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v);
        }
        sbt[u] += sbt[v];
    }
    sbt[u] += 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test, n, caseno = 1;

    cin>>test;

    while(test--){
        cin>>n;
        memset(sbt, 0, sizeof(sbt));
        memset(ans, 0, sizeof(ans));
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= n; i++){
            cin>>parent[i];
            if(parent[i] != 0){
                graph[parent[i]].pb(i);
            }
        }
        for(int i = 1; i <= n; i++){
            if(!visited[i])
                dfs(i);
        }
        // for(int i = 1; i <= n; i++){
        //     cout<<"Subtree "<<i<<": "<<sbt[i]<<endl;
        // }

        cout<<"Forest#"<< caseno++ <<": ";
        for(int i = 1; i <= n; i++){
            int sum = 0;
            for(int j = 0; j < graph[i].size(); j++){
                sum += sbt[graph[i][j]];
            }
            ans[i] += (sbt[i] - 1);
            for(int j = 0; j < (int) (graph[i].size() - 1); j++){
                ans[i] += (sum - sbt[graph[i][j]]) * sbt[graph[i][j]];
                sum -= sbt[graph[i][j]];
            }
        }

        for(int i = 1; i < n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<ans[n]<<endl;

        for(int i = 1; i <= n; i++)
            graph[i].clear();
    }
    return 0;
}
