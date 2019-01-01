#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int degree[500000] = {0};
vector<int> graph[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, a, b, visited[MAX];

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        degree[a]++;
        degree[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 0;
    bool flag = true;

    while(flag){
        flag = false;
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= n; i++){
            if(degree[i] == 1){
                flag = true;
                for(int j = 0; j < graph[i].size(); j++){
                    visited[graph[i][j]]++;
                }
                degree[i] = 0;
            }
        }

        for(int i = 1; i <= n; i++){
            if(visited[i] > 0){
                degree[i] -= visited[i];
            }
        }
        if(flag){
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
