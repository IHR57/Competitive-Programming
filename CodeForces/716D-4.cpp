#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;
const ll inf = 1000000000000000000;

ll cost[MAX][MAX], cost1[MAX][MAX], dist1[MAX], dist2[MAX], dist[MAX][MAX];
vector<ll> graph1[MAX], graph2[MAX];
int parent[MAX], Left[MAX*10], Right[MAX*10];
int n, m, l, source, destination;

struct data
{
    int node;
    ll weight;
};
bool operator<(data A, data B)
{
    return A.weight > B.weight;
}

ll dijkstra()
{
    for(int i = 0; i < MAX; i++)
        dist1[i] = inf;

    data u, v;
    priority_queue<data> pq;

    u.node = source, u.weight = 0;
    dist1[u.node] = 0;
    pq.push(u);

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        for(int i = 0; i < graph1[u.node].size(); i++){
            v.node = graph1[u.node][i];
            v.weight = cost[u.node][v.node] + dist1[u.node];
            if(v.weight < dist1[v.node]){
                dist1[v.node] = v.weight;
                pq.push(v);
            }
        }
    }

    return dist1[destination];
}

bool dijkstra2()
{
    for(int i = 0; i < MAX; i++)
        dist2[i] = inf;
    data u, v;
    priority_queue<data> pq;

    u.node = source, u.weight = 0;
    dist2[u.node] = 0;
    pq.push(u);

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        for(int i = 0; i < graph2[u.node].size(); i++){
            v.node = graph2[u.node][i];
            v.weight = abs(cost[u.node][v.node]) + dist2[u.node];
            if(v.weight < dist2[v.node]){
                dist2[v.node] = v.weight;
                parent[v.node] = u.node;
                pq.push(v);
            }
        }
    }

    if(dist2[destination] > l){
        return false;
    }
    int current = destination;
    while(current != source){
        int p = parent[current];
        if(cost[p][current] < 0)
            cost[p][current] = cost[current][p] = -2;
        current = parent[current];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cost[i][j] == -1)
                cost[i][j] = inf;       //block the edge which are not in shortest path
        }
    }

    current = destination;
    while(current != source){
        int p = parent[current];
        if(cost[p][current] < 0)
            cost[p][current] = cost[current][p] = -1;
        current = parent[current];
    }

    return true;
}

bool relax()
{
    memset(parent, -1, sizeof(parent));
    for(int i = 0; i < MAX; i++)
        dist2[i] = inf;
    data u, v;
    priority_queue<data> pq;

    u.node = source, u.weight = 0;
    dist2[u.node] = 0;
    pq.push(u);

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        for(int i = 0; i < graph2[u.node].size(); i++){
            v.node = graph2[u.node][i];
            v.weight = abs(cost[u.node][v.node]) + dist2[u.node];
            if(v.weight < dist2[v.node]){
                dist2[v.node] = v.weight;
                parent[v.node] = u.node;
                pq.push(v);
            }
        }
    }

    if(dist2[destination] == l)
        return true;
    int current = destination; bool meet = false;
    while(current != source){
        int p = parent[current];
        if(!meet && cost[p][current] < 0){
            ll d = abs(cost[p][current]);
            cost[p][current] = cost[current][p] = d + l - dist2[destination];
            meet = true;
        }
        if(meet)
            break;
        current = parent[current];
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n>>m>>l>>source>>destination;

    memset(cost1, -1, sizeof(cost1));

    for(int i = 0; i < m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        if(w > 0){
            graph1[u].push_back(v), graph1[v].push_back(u);
            graph2[u].push_back(v), graph2[v].push_back(u);
            cost[u][v] = w, cost[v][u] = w;
            cost1[u][v] = w, cost1[v][u] = w;
        }
        else{
            graph2[u].push_back(v), graph2[v].push_back(u);
            cost[u][v] = -1, cost[v][u] = -1;
        }
        Left[i] = u, Right[i] = v;
    }

    ll result = dijkstra();
    // cout<<result<<endl;

    if(result < l){     //there exists a shortest path less than L. So there is no solution
        cout<<"NO"<<endl;
        return 0;
    }

    if(result == l){        //there exists a solution
        cout<<"YES"<<endl;
        for(int i = 0; i < m; i++){
            ll temp = cost[Left[i]][Right[i]];
            if(cost[Left[i]][Right[i]] <= 0)
                temp = inf;
            cout<<Left[i]<<" "<<Right[i]<<" "<<temp<<endl;
        }
        return 0;
    }

    bool tmp = dijkstra2();
    if(!tmp){
        cout<<"NO"<<endl;
        return 0;
    }

    while(!relax()){
        relax();
    }

    cout<<"YES"<<endl;
    for(int i = 0; i < m; i++){
        int u = Left[i], v = Right[i];
        ll d = cost[u][v];
        if(d < 0)
            d = -d;
        cout<<u<<" "<<v<<" "<<d<<endl;
    }

    return 0;
}
