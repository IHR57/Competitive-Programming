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

#define MAX 10005
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int inf = 1<<28;

vector<vii> graph, revGraph;
vi dist, revDist;          //distance and reverse distance
//int cost[MAX][MAX];

void dijkstra1(int source)
{
    priority_queue<pii, vii, greater<pii> >pq;
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

void dijkstra2(int source)
{
    priority_queue<pii, vii, greater<pii> >pq;
    revDist[source] = 0;
    pq.push(pii(source, 0));

    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();

        for(int i = 0; i < revGraph[top.first].size(); i++){
            pii x = revGraph[top.first][i];
            if(revDist[x.first] > revDist[top.first] + x.second){
                revDist[x.first] = revDist[top.first] + x.second;
                pq.push(pii(x.first, revDist[x.first]));
            }
        }
    }
}

int main()
{
    int test, n, m, source, destination, caseNo = 1;
    int u, v, w;
    int totalMoney, Great;

    scanf("%d", &test);

    while(test--){
        //memset(cost, 0, sizeof(cost));
        scanf("%d %d %d %d %d", &n, &m, &source, &destination, &totalMoney);
        source--, destination--;
        dist = vi(n + 1, inf);          //initializing distance and reverse Distance
        revDist = vi(n + 1, inf);
        graph = vector<vii> (n + 1, vii());
        revGraph = vector<vii> (n + 1, vii());

        while(m--){
            scanf("%d %d %d", &u, &v, &w);
            //cost[u][v] = w;
            u--, v--;
            graph[u].pb(pii(v, w));
            revGraph[v].pb(pii(u, w));
        }

        Great = -1;
        dijkstra1(source);          //run Dijkstra in original graph
        dijkstra2(destination);     //run Dijkstra in reversed graph

        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                pii temp = graph[i][j];
                int sum = dist[i] + revDist[temp.first] + graph[i][j].second;
                //cout<<sum<<" "<<cost[i][temp.first]<<endl;
                if(sum <= totalMoney)
                    Great = max(Great, graph[i][j].second);
            }
        }

        printf("Case %d: %d\n", caseNo++, Great);
    }

    return 0;

}
