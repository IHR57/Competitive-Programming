#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define MAX 105
#define pb push_back
using namespace std;

typedef long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

const int inf = 1<<28;
int dist[MAX];
vector<vii> graph;

void dijkstra(int source)
{
    priority_queue<pii, vii, greater<pii> >pq;

    for(int i = 0; i < MAX; i++)
        dist[i] = inf;

    dist[source] = 0;
    pq.push(pii(source, 0));

    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();

        for(int i = 0; i < graph[top.first].size(); i++){
            pii x = graph[top.first][i];
            if(dist[x.first] > dist[top.first] + x.second){
                dist[x.first] = dist[top.first] + x.second;
                pq.push(pii(x.first, dist[x.first]));
            }
        }
    }
}

int main()
{
    int totalNode, exitCell, timeUnit, totalEdge;
    int u, v, w;

    scanf("%d %d %d %d", &totalNode, &exitCell, &timeUnit, &totalEdge);

    graph = vector<vii> (totalNode + 2, vii());

    for(int i = 0; i < totalEdge; i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[v].pb(pii(u, w));
    }

    dijkstra(exitCell);     //run dijkstra from exit cell

    int count = 0;
    for(int i = 1; i <= totalNode; i++){
        if(dist[i] <= timeUnit){            //if distance is less thatn equal given time unit
            count++;        //the mice escape the maze so we have to increment the counter
        }
    }

    printf("%d\n", count);

    return 0;
}
