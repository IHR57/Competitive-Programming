//Problem ID: LightOJ - 1123 (Trail Maintenance)
//Programmer: IQBAL HOSSAIN     Description: DFS
//Date: 04/04/19
//Notes: Can be solved using MST
#include <bits/stdc++.h>
#define MAX 205
using namespace std;

int cost[MAX][MAX];
vector<int> graph[MAX];
int visited[MAX], parent[MAX];
int sum;

void dfs(int u)
{
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            sum += cost[u][v];
            parent[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    int test, caseno = 1;
    int n, m, u, v, w;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        printf("Case %d:\n", caseno++);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &w);
            memset(visited, 0, sizeof(visited));
            memset(parent, -1, sizeof(parent));
            dfs(v);
            if(!visited[u]){
                graph[u].push_back(v);
                graph[v].push_back(u);
                cost[u][v] = cost[v][u] = w;
            }
            else{
                int tempu = -1, tempv = -1, Max = -1;
                for(int j = u; j != -1; j = parent[j]){
                    int k = parent[j];
                    if(cost[j][k] > Max){
                        Max = cost[j][k], tempu = j, tempv = k;
                    }
                }
                if(Max > w){
                    cost[tempu][tempv] = cost[tempv][tempu] = -1;
                    for(int j = 0; j < graph[tempu].size(); j++){
                        if(graph[tempu][j] == tempv){
                            graph[tempu].erase(graph[tempu].begin() + j);
                            break;
                        }
                    }
                    for(int j = 0; j < graph[tempv].size(); j++){
                        if(graph[tempv][j] == tempu){
                            graph[tempv].erase(graph[tempv].begin() + j);
                            break;
                        }
                    }
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                    cost[u][v] = cost[v][u] = w;
                }
            }
            memset(visited, 0, sizeof(visited));
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                if(!visited[i]){
                    sum = 0;
                    cnt++;
                    dfs(i);
                }
            }
            if(cnt >= 2){
                printf("-1\n");
            }
            else{
                printf("%d\n", sum);
            }
        }
        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}
