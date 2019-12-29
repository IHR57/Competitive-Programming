//Problem ID: AtCoder - abc126_d (Even Relation)
//Programmer: IQBAL HOSSAIN     Description: DFS
//Date: 29/05/19
//Problem Link: https://atcoder.jp/contests/abc126/tasks/abc126_d
#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
using namespace std;

typedef pair<int, int> pii;

vector<pii> graph[MAX];
int color[MAX];

void dfs(int u, int par)
{
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i].first;
        if(v == par)
            continue;
        if(graph[u][i].second % 2 == 0){
            color[v] = color[u];
        }
        else
            color[v] = !color[u];
        dfs(v, u);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, u, v, w;

    cin>>n;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v>>w;
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }

    color[1] = 0;
    dfs(1, - 1);

    for(int i = 1; i <= n; i++){
        cout<<color[i]<<endl;
    }

    return 0;
}