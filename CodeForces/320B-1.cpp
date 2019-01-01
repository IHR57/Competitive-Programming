#include <bits/stdc++.h>
#define MAX 105
using namespace std;

const int inf = 2147483647;
vector<int> graph[MAX];
int visited[MAX];

int bfs(int source, int destination)
{
    memset(visited, 0, sizeof(visited));
    visited[source] = 1;

    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    return visited[destination];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l[MAX], r[MAX], c, left, right;

    cin>>n;

    int k = 1;

    for(int i = 1; i <= n; i++){
        cin>>c;
        if(c == 1){
            cin>>l[k]>>r[k];
            for(int j = 1; j < k; j++){
                if((l[k] > l[j] && l[k] < r[j]) || (r[k] > l[j] && r[k] < r[j])){
                    graph[k].push_back(j);
                }
                if((l[j] > l[k] && l[j] < r[k]) || (r[j] > l[k] && r[j] < r[k])){
                    graph[j].push_back(k);
                }
            }
            k++;
        }
        else{
            cin>>left>>right;
            if(bfs(left, right)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
