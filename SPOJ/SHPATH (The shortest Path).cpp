#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>
#include <cstring>
#include <queue>
#define MAX 10005
#define pb push_back
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;
vector<int> graph[MAX], cost[MAX];
int dist[MAX];
const int inf = 1<<29;

struct node
{
    int city, weight;
};

bool operator<(node A, node B)      //operator overloading
{
    return A.weight > B.weight;
}

int dijkstra(int source, int destination)
{
    for(int i = 0; i < MAX; i++)
        dist[i] = inf;

    priority_queue<node> pq;
    node u, v;
    u.city = source, u.weight = 0;
    dist[source] = 0;
    pq.push(u);

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        for(int i = 0; i < graph[u.city].size(); i++){
            v.city = graph[u.city][i];
            v.weight = cost[u.city][i] + dist[u.city];
            if(dist[v.city] > v.weight){
                dist[v.city] = v.weight;
                pq.push(v);
            }
        }
    }

    return dist[destination];
}

int main()
{
    int test, numberOfCity, u, v, w, neighbour, query;
    char str[40], source[40], destination[40];

    scanf("%d", &test);

    while(test--){
        scanf("%d", &numberOfCity);
        int idx = 1;
        map<string, int> myMap;
        while(numberOfCity--){
            scanf("%s", str);
            if(myMap.find(str) == myMap.end()){     //mapping
                myMap[str] = idx++;
            }
            scanf("%d", &neighbour);        //number of connected node with this city
            u = myMap[str];             //integer id of the city
            while(neighbour--){
                scanf("%d %d", &v, &w);
                graph[u].pb(v);     //directed graph
                cost[u].pb(w);
            }
        }
        scanf("%d", &query);        //number of query
        for(int i = 0; i < query; i++){
            scanf("%s %s", source, destination);
            int s = myMap[source], t = myMap[destination];      //getting integer id of city
            int result = dijkstra(s, t);        //run dijkstra

            printf("%d\n", result);
        }

        for(int i = 0; i < MAX; i++){
            graph[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
