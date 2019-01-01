#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int visited[MAX][MAX], blocked[MAX] = {0};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, u, v;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        visited[u][v] = 1;
        visited[v][u] = 1;
        blocked[u] = 1;
    }

    for(int i = 1; i <= n; i++){
        bool flag = true;
        if(!blocked[i]){
            for(int j = 1; j <= n; j++){
                if(j != i){
                    if(visited[i][j] == 1 || visited[j][i] == 1){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(!blocked[i] && flag){
            cout<<n-1<<endl;
            for(int j = 1; j <= n; j++){
                if(i != j){
                    cout<<i<<" "<<j<<endl;
                }
            }
            return 0;
        }
    }

    return 0;
}
