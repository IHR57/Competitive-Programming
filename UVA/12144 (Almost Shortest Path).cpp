#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#define MAX 505
#define pb push_back
using namespace std;

typedef long long lint;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int inf = 1<<28;

int nodeNo, edge, source, destination;
vector<vii> neighbors;
vi parents;
vi dist;
vii edgeToAvoid;

void storeEdges(int node, int parent)
{
    while(parent != -1){
        edgeToAvoid.push_back(ii(parent, node));
        node = parent;
        parent = parents[parent];
    }
}

void dijkstra1()
{
    priority_queue<ii, vii, greater<ii> >pq;
    dist[source] = 0;
    pq.push(ii(source, 0));

    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();

        for(int j = 0; j < neighbors[top.first].size(); j++){
            ii x = neighbors[top.first][j];
            if(x.first == destination){
                if(dist[x.first] == dist[top.first] + x.second){
                    storeEdges(destination, top.first);
                    continue;
                }
            }
            if(dist[x.first] > dist[top.first] + x.second){
                dist[x.first] = dist[top.first] + x.second;
                parents[x.first] = top.first;
                pq.push(ii(x.first, dist[x.first]));
                if(x.first == destination){
                    edgeToAvoid.clear();
                    storeEdges(destination, top.first);
                }
            }
        }
    }
}

void dijkstra2()
{
    priority_queue<ii, vii, greater<ii> >pq;
    dist[source] = 0;
    pq.push(ii(source, 0));

    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();

        for(int j = 0; j < neighbors[top.first].size(); j++){
            ii x = neighbors[top.first][j];
            if(find(edgeToAvoid.begin(), edgeToAvoid.end(), ii(top.first, x.first)) == edgeToAvoid.end()){
                if(dist[x.first] > dist[top.first] + x.second){
                    dist[x.first] = dist[top.first] + x.second;
                    pq.push(ii(x.first, dist[x.first]));
                }
            }
        }
    }
}

int main()
{
    int u, v, w;

    while(true){
        scanf("%d %d", &nodeNo, &edge);
        if(!nodeNo && !edge)
            break;
        dist = vi(nodeNo, inf);
        parents = vi(nodeNo, -1);         //fill parents with -1
        neighbors = vector<vii> (nodeNo, vii());

        scanf("%d %d", &source, &destination);
        while(edge--){
            scanf("%d %d %d", &u, &v, &w);      //path u to v with cost w
            neighbors[u].push_back(ii(v, w));
        }

        dijkstra1();        //run dijkstra to select the edges which have to avoid

        if(dist[destination] == inf){
            printf("-1\n");
            continue;           //do not need to check others
        }

        dist = vi(nodeNo, inf);         //re-initialize distance
        //parents = vi(nodeNo, -1);

        dijkstra2();        //run dijkstra again to find second shortest path

        if(dist[destination] == inf){
            printf("-1\n");
        }
        else{
            printf("%d\n", dist[destination]);
        }

    }

    return 0;
}
