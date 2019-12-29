//Problem ID: CodeForces - 986A (Fair)
//Programmer: IQBAL HOSSAIN     Description: Graphs
//Date: 23/04/19
#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
using namespace std;

typedef priority_queue<int, vector<int>, greater<int> > PQ;

int visited[MAX], dist[MAX];
vector<int> graph[MAX];
vector<int> food[105];
int res[MAX][105];

int main()
{
    int n, m, k, s, val;

    scanf("%d %d %d %d", &n, &m, &k, &s);

    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        val--;
        food[val].pb(i);
    }
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u,  &v);
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for(int i = 0; i < k; i++){
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        queue<int> q;
        for(int j = 0; j < food[i].size(); j++){
            q.push(food[i][j]);
            dist[food[i][j]] = 0;
            visited[food[i][j]] = 1;
            res[food[i][j]][i] = 0;
        }

        while(!q.empty()){
            u = q.front();
            q.pop();

            for(int j = 0; j < graph[u].size(); j++){
                v = graph[u][j];
                if(!visited[v]){
                    visited[v] = 1;
                    dist[v] = dist[u] + 1;
                    res[v][i] = dist[v];
                    q.push(v);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        nth_element(res[i], res[i] + s, res[i] + k);
        int sum = 0;
        for(int j = 0; j < s; j++){
            sum += res[i][j];
        }
        printf("%d ", sum);
    }
    printf("\n");

    return 0;
}
