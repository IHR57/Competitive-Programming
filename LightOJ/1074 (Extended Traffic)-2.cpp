#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 205
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int inf = 1<<28;

int cost[MAX], dist[MAX];
vi graph[MAX];
int nodeNo, edgeNo;

int Cube(int a, int b)
{
    return ((cost[a] - cost[b]) * (cost[a] - cost[b]) * (cost[a] - cost[b]));
}

void bellmanFord(int source)
{
    for(int i = 0; i < MAX; i++){           //initialize distance
        dist[i] = inf;
    }

    dist[source] = 0;

    for(int k = 1; k < nodeNo; k++){
        for(int i = 1; i <= nodeNo; i++){
            for(int j = 0; j < graph[i].size(); j++){
                int u = i;
                int v = graph[i][j];
                if(dist[u] == inf && dist[v] == inf){
                    continue;
                }
                if(dist[v] > dist[u] + Cube(v, u)){     //update if it is possible
                    dist[v] = dist[u] + Cube(v, u);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio (false); cin.tie(NULL);
    int test, u, v, query, destination, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &nodeNo);
        for(int i = 1; i <= nodeNo; i++)
            scanf("%d", &cost[i]);

        scanf("%d", &edgeNo);

        for(int i = 1; i <= edgeNo; i++){
            scanf("%d %d", &u, &v);     //directed graph
            graph[u].push_back(v);
        }

        bellmanFord(1);         //run bellmanFord from source 1

        scanf("%d", &query);        //number of query to be answered

        printf("Case %d:\n", caseNo++);

        while(query--){
            scanf("%d", &destination);
            if(dist[destination] >= 3 && dist[destination] != inf)
                printf("%d\n",dist[destination]);
            else
                printf("?\n");
        }

        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}

