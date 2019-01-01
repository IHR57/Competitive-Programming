// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

vector<int> graph[MAX];
int arr[MAX], visited[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, u, v;

    cin>>n>>m;
    memset(visited, 0, sizeof(visited));

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    ll sum = 0;
    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    for(int i = 1; i <= n; i++){
        queue<int> q;
        int Min = arr[i];
        if(graph[i].size() && !visited[i]){
            q.push(i);
            visited[i] = 1;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(int j = 0; j < graph[u].size(); j++){
                    int v = graph[u][j];
                    if(!visited[v]){
                        visited[v] = 1;
                        q.push(v);
                        Min = min(Min, min(arr[u], arr[v]));
                    }
                }
            }
            sum += (ll) Min;
        }
        else if(!visited[i]){
            sum += (ll) arr[i];
        }
    }


    cout<<sum<<endl;

    return 0;
}
