//Problem ID: CodeForces - 687A (NP-Hard Problem)
//Programmer: IQBAL HOSSAIN     Description: Graph (Bipartite Graph)
//Date: 30/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
int visited[MAX];
bool flag = false;

void dfs(int u, int c)
{
    visited[u] = c;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(visited[v] == -1){
            dfs(v, !c);
        }
        if(visited[v] == c){
            flag = true;
            return;
        }

    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int u, v, n, m;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(visited, -1, sizeof(visited));

    for(int i = 1; i <= n; i++){
        if(visited[i] == -1){
            dfs(i, 0);
        }
    }

    if(flag){
        cout<<-1<<endl;
        return 0;
    }

    vector<int> pari, arya;

    for(int i = 1; i <= n; i++){
        if(visited[i] == 0)
            pari.push_back(i);
        else
            arya.push_back(i);
    }

    cout<<pari.size()<<endl;

    for(int i = 0; i < pari.size(); i++){
        cout<<pari[i]<<" ";
    }
    cout<<endl;

    cout<<arya.size()<<endl;
    for(int i = 0; i < arya.size(); i++){
        cout<<arya[i]<<" ";
    }
    cout<<endl;

    return 0;
}
