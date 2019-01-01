#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

vector<int> graph[MAX];
int visited[MAX], numberofEdges, vertices;

void dfs(int u)
{
    visited[u] = 1;
    vertices++;
    numberofEdges += graph[u].size();

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            //degree[v]--;
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

    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            numberofEdges = 0;
            vertices = 0;
            dfs(i);
            //numberofEdges /= 2;
            //cout<<numberofEdges<<endl;
            if((long long) vertices * (vertices - 1)  != numberofEdges){
                flag = false;
                break;
            }
        }
    }

    (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    return 0;
}
