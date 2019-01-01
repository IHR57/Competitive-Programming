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

#define MAX 5005
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int inf = 1<<28;

vector<vii> graph;
vi parents;

void dijkstra(int source, int dist[])
{
    priority_queue<pii, vii, greater<pii> >pq;
    dist[source] = 0;       //distance of the source node
    pq.push(pii(source, 0));        //pushing source node into the priority queue

    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();

        for(int i = 0; i < graph[top.first].size(); i++){
            pii x = graph[top.first][i];
            if(dist[x.first] > dist[top.first] + x.second){     //update cost
                dist[x.first] = dist[top.first] + x.second;
                parents[x.first] = top.first;        //update parents
                pq.push(pii(x.first, dist[x.first]));
            }
        }
    }
}

int main()
{
    int test, caseNo = 1, nodeNo, edgeNo, u, v, w;
    int dist[MAX], revDist[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &nodeNo, &edgeNo);

        graph = vector<vii> (nodeNo + 1, vii());

        for(int i = 0; i < edgeNo; i++){
            scanf("%d %d %d", &u, &v, &w);
            graph[u].pb(pii(v, w));
            graph[v].pb(pii(u, w));
        }

        for(int i = 0; i < MAX; i++){           //initialize distance and revDistance
            dist[i] = inf;
            revDist[i] = inf;
        }

        parents = vi(nodeNo + 1, -1);
        dijkstra(nodeNo, revDist);          //now last node becomes source node and run dijkstra
        parents = vi(nodeNo + 1, -1);       //again initialize parents
        dijkstra(1, dist);      //run dijkstra 1 as a source node

        set<int> s;
        int Min = inf;

        /*for(int i = 1; i <= nodeNo; i++){
            printf("%d = %d\n", i, revDist[i]);
        }*/
        for(int i = 1; i <= nodeNo; i++){
            for(int j = 0; j < graph[i].size(); j++){
                pii temp = graph[i][j];
                //cout<<graph[1][j].first<<endl;
                if(i == 1 && parents[graph[1][j].first] != -1){
                    if(graph[1][j].second < Min)
                        Min = graph[1][j].second;
                }
                if(i != 1 && parents[i] != -1 && parents[graph[i][j].first] != -1){   //if the edge is a part of shortest path
                    if(graph[i][j].second < Min){           //find the minimum edge in shortest path
                        Min = graph[i][j].second;
                    }
                }
                int sum = dist[i] + revDist[temp.first] + graph[i][j].second;
               // cout<<sum<<endl;
                if(sum < inf)
                    s.insert(sum);
            }
        }

        int ans, count = 0;
        int firstElement, secondElement;

        set<int>::iterator it;
        for(it = s.begin(); it != s.end(); it++){
            count++;
            if(count == 1)
                firstElement = *it;
            if(count == 2)
                secondElement = *it;
        }
        if(count == 1){
            printf("Case %d: %d\n", caseNo++, firstElement + 2 * Min);
        }
        else{
            if((firstElement + 2 * Min) < secondElement){
                printf("Case %d: %d\n", caseNo++, (firstElement + 2 * Min));
            }
            else
                printf("Case %d: %d\n", caseNo++, secondElement);
        }
        s.clear();
    }

    return 0;
}

