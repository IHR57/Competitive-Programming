//Problem ID: LightOJ - 1108 (Instant View of Big Bang)
//Programmer: IQBAL HOSSAIN     Description: SCC/Bellman Ford
//Date: 04/04/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

vector<int> graph[MAX], rgraph[MAX];
const int inf = 1<<28;

struct edge{
    int a, b, c;

    edge(int t1, int t2, int t3){
        a = t1, b = t2, c = t3;
    }
};

vector<edge> e;
vector<int> scc[MAX];
int finish[MAX], finishing_time, cmpnt, visited[MAX], mark[MAX], n;

void dfs(int u)
{
    finishing_time++;
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v])
            dfs(v);
    }
    finish[u] = ++finishing_time;
}

void dfs2(int u)
{
    visited[u] = 1;
    scc[cmpnt].push_back(u);
    for(int i = 0; i < rgraph[u].size(); i++){
        int v = rgraph[u][i];
        if(!visited[v])
            dfs2(v);
    }
}

void dfs3(int u)
{
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v])
            dfs3(v);
    }
}

bool bellmanFord(int src, vector<edge> v)           //call this if we don't have to print negative cycle
{
    vector<int> dist(n, inf);
    dist[src] = 0;

    bool isAnyUpdate;

    for(int i = 0; i < n; i++){
        isAnyUpdate = false;
        for(int j = 0; j < v.size(); j++){
            if(dist[v[j].a] < inf){         //if the graph contains negative weight edges
                if(dist[v[j].a] + v[j].c < dist[v[j].b]){
                    dist[v[j].b] = dist[v[j].a] + v[j].c;
                    isAnyUpdate = true;
                }
            }
        }
    }
    if(isAnyUpdate)
        return true;
    return false;
}

int main()
{
    int test, m, u, v, cost, caseno = 1;

    scanf("%d", &test);

    while((test--)){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &cost);
            graph[u].push_back(v);
            rgraph[v].push_back(u);
            e.push_back(edge(u, v, cost));
        }

        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < n; i++){
            if(!visited[i])
                dfs(i);
        }
        memset(visited, 0, sizeof(visited));
        vector<pair<int, int> > vp;
        vector<int> res;
        for(int i = 0; i < n; i++)
            vp.push_back(make_pair(finish[i], i));

        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());

        cmpnt = 0;
        for(int i = 0; i < n; i++){
            int m = vp[i].second;
            if(!visited[m]){
                dfs2(m);
                cmpnt++;
            }
        }
        memset(mark, 0, sizeof(mark));
        for(int i = 0; i < cmpnt; i++){
            memset(visited, 0, sizeof(visited));
            for(int j = 0; j < scc[i].size(); j++){
                visited[scc[i][j]] = 1;
            }
            vector<edge> temp;
            for(int j = 0; j < m; j++){
                int x = e[j].a, y = e[j].b;
                if(visited[x] && visited[y]){
                    temp.push_back(edge(x, y, e[j].c));
                }
            }
            if(bellmanFord(scc[i][0], temp)){
                //cout<<"Negative Cycle Detected"<<endl;
                for(int j = 0; j < scc[i].size(); j++){
                    res.push_back(scc[i][j]);
                    mark[scc[i][j]] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!mark[i]){
                memset(visited, 0, sizeof(visited));
                dfs3(i);
                for(int j = 0; j < res.size(); j++){
                    if(visited[res[j]]){
                        res.push_back(i);
                        mark[res[j]] = 1;
                        break;
                    }
                }
            }
        }
        printf("Case %d: ", caseno++);
        e.clear();
        for(int i = 0; i < n; i++){
            graph[i].clear();
            rgraph[i].clear();
            scc[i].clear();
        }
        if(res.empty()){
            printf("impossible\n");
            continue;
        }
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size() - 1; i++){
            printf("%d ", res[i]);
        }
        printf("%d\n", res[res.size()-1]);
    }

    return 0;

}
