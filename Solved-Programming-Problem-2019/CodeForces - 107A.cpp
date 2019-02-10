//Problem ID: CodeForces - 107A (Dorm and Water Supply)
//Programmer: IQBAL HOSSAIN     Description: DFS and Similar
//Date: 06/02/19
//Problem Link: https://codeforces.com/contest/107/problem/A
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;

int cost[MAX];
int graph[MAX], dis[MAX];
int visited[MAX], vis[MAX];

void dfs(int u)
{
    vis[u] = 1;
    int v = graph[u];
    dis[v] = min(dis[u], cost[u]);
    if(v != -1 && !vis[v])
        dfs(v);
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, p, inD[MAX] = {0}, outD[MAX] = {0};
    vector<int> tank, tap;

    cin>>n>>p;

    int a, b, d;
    for(int i = 0; i < MAX; i++)
        dis[i] = 1<<28;

    memset(graph, -1, sizeof(graph));

    for(int i = 0; i < p; i++){
        cin>>a>>b>>d;
        inD[b]++;
        outD[a]++;
        graph[a] = b;
        cost[a] = d;
    }

    for(int i = 1; i <= n; i++){
        if(graph[i] != -1){
            memset(vis, 0, sizeof(vis));
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++){
        if(inD[i] == 0 && outD[i] == 1){
            tank.push_back(i);
        }
        else if(inD[i] == 1 && outD[i] == 0){
            tap.push_back(i);
        }
    }

    if(tap.size() == 0 || tank.size() == 0){
        cout<<0<<endl;
        return 0;
    }

    cout<<min(tank.size(), tap.size())<<endl;

    for(int i = 0; i < tank.size(); i++){
        memset(vis, 0, sizeof(vis));
        dfs(tank[i]);
        for(int j = 0; j < tap.size(); j++){
            if(vis[tap[j]]){
                cout<<tank[i]<<" "<<tap[j]<<" "<<dis[tap[j]]<<endl;
            }
        }
    }

    return 0;
}
