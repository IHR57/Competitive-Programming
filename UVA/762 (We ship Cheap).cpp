#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> graph[700];
int dist[700], used[700], pre[700];

const int INF = 1 << 28;

void spfa(int ed, int st)
{
    int i, u;
    for(int i = 0; i < 700; i++){
        dist[i] = INF;
        used[i] = 0;
    }
    dist[st] =  0;
    pre[st] = st;

    queue<int> q;
    q.push(st);

    while(!q.empty()){
        u = q.front();
        used[u] = 0;
        q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            if(dist[graph[u][i]] > dist[u] + 1){
                dist[graph[u][i]] = dist[u] + 1;
                pre[graph[u][i]] = u;

                if(used[graph[u][i]] == 0){
                    used[graph[u][i]] = 1;
                    q.push(graph[u][i]);
                }
            }
        }
    }

    if(dist[ed] == INF)
        puts("No route");
    else{
        int idx = ed;

        while(dist[idx]){
            printf("%c%c %c%c\n", idx/26+'A', idx%26+'A', pre[idx]/26+'A', pre[idx]%26+'A');
            idx = pre[idx];
        }
    }
}

int main()
{
    int n;
    char x[30], y[30];
    int first = 0;

    while(scanf("%d", &n) == 1){
        if(first)
            puts("");
        first = 1;
        int xx, yy, i;

        for(i = 0; i < 700; i++){
            graph[i].clear();
        }

        while(n--){
            scanf("%s %s", x, y);

            xx = (x[0] - 'A') * 26 + x[1] - 'A';
            yy = (y[0] - 'A') * 26 + y[1] - 'A';
            graph[xx].push_back(yy);
            graph[yy].push_back(xx);
        }

        scanf("%s %s", x, y);
        xx = (x[0] - 'A') * 26 + x[1] - 'A';
        yy = (y[0] - 'A') * 26 + y[1] - 'A';
        spfa(xx, yy);
    }

    return 0;
}
