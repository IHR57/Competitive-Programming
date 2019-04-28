//Problem ID: CodeForces 954D (Fight Against Traffic)
//Programmer: IQBAL HOSSAIN     Description: DFS/BFS/Shortest Paths
//Date: 28/04/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef pair<int, int> pii;
vector<int> graph[MAX];
map<pii, int> mp;
int visited[MAX];

void bfs(int s, int dist[])
{
    visited[s] = 1;
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, distS[MAX], distT[MAX], s, t, u, v;

    cin>>n>>m>>s>>t;
    int idx = 1;
    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if(mp[make_pair(u, v)] == 0 && mp[make_pair(v, u)] == 0){
            mp[make_pair(u, v)] = idx++;
            mp[make_pair(v, u)] = idx++;
        }
    }

    memset(visited, 0, sizeof(visited));
    bfs(s, distS);
    memset(visited, 0, sizeof(visited));
    bfs(t, distT);

    int ans = distS[t], cnt = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(mp[make_pair(i, j)] == 0){
                int temp1 = distS[i] + 1 + distT[j];
                int temp2 = distT[i] + 1 + distS[j];
                if(min(temp1, temp2) >= ans){
                    cnt++;
                }
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
