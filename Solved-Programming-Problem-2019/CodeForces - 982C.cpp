//Problem ID: CodeForces - 982C (Cut'em all)
//Programmer: IQBAL HOSSAIN     Description: DFS/BFS
//Date: 23/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
int dist[MAX], visited[MAX];

void dfs(int u)
{
    visited[u] = 1;
    int v, sum = 0;
    for(int i = 0; i < graph[u].size(); i++){
        v = graph[u][i];
        if(!visited[v]){
            dfs(v);
            sum += dist[v];
        }
    }
    dist[u] = sum + 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u, v;

    cin>>n;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(n % 2){
        cout<<-1<<endl;
        return 0;
    }

    dfs(1);

    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            v = graph[u][i];
            if(!visited[v]){
                if(dist[v] % 2 == 0){
                    cnt++;
                }
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
