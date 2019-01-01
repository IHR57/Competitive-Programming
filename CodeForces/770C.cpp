#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

bool cycle;
vector<int> graph[MAX], ts;
int visited[MAX];

void dfs(int u)
{
    if(visited[u] == 0){
        visited[u] = 1;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            dfs(v);
        }
        visited[u] = 2;
        ts.push_back(u);
    }
    else if(visited[u] == 1){
        cycle = true;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, courses[MAX], u, v;

    cin>>n>>k;
    for(int i = 0; i < k; i++){
        cin>>courses[i];
    }

    for(int i = 1; i <= n; i++){
        cin>>u;
        while(u--){
            cin>>v;
            graph[i].push_back(v);
        }
    }

    for(int i = 0; i < k; i++){
        if(cycle){
            cout<<-1<<endl;
            return 0;
        }
        dfs(courses[i]);
    }

    if(cycle){
        cout<<-1<<endl;
        return 0;
    }

    cout<<ts.size()<<endl;
    for(int i = 0; i < ts.size(); i++){
        cout<<ts[i]<<" ";
    }
    cout<<endl;

    return 0;
}
