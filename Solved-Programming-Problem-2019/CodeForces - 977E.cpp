//Problem ID: CodeForces - 977E (Cyclic Components)
//Programmer: IQBAL HOSSAIN     Description: DFS
//Date: 24/02/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

vector<int> graph[MAX];
bool isCyclic;
int visited[MAX];

void dfs(int u)
{
    visited[u] = 1;
    if(graph[u].size() != 2)
        isCyclic = false;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, u, v;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            isCyclic = true;
            dfs(i);
            if(isCyclic){
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
