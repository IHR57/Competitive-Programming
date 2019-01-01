#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#define MAX 400
using namespace std;

string id[MAX];
string temp, first, second;
char graph[MAX][MAX];
char color[MAX];
int nc, dist[MAX];
const int INF = 1<<28;

void init()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            graph[i][j] = '0';
        }
    }
}

int getId(string one)
{
    for(int i = 0; i < nc; i++){
        if(id[i] == one)
            return i;
    }

    id[nc] = one;

    return nc++;
}

int breadthFirst(int source, int destination)
{
    for(int i = 0; i < nc; i++){
        color[i] = 'w';
        dist[i] = INF;
    }

    queue<int> q;

    color[source] = 'g';
    dist[source] = 0;
    q.push(source);


    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < nc; i++){
            if(graph[u][i] == '1' && color[i] == 'w'){
                color[i] = 'g';
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }

        color[u] = 'b';
    }

    if(dist[destination] == INF){       //if the node does not exits
        return -1;
    }

    return dist[destination];
}

int main()
{
    int test, node, edge, request, k, cases = 1;

    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
    cin>>test;

    while(test--){
        cin>>node>>edge>>request;

        nc = 0;
        init();
        for(int i = 0; i < node; i++){
            cin>>temp;
            k = getId(temp);
        }

        int a, b;
        for(int i = 0; i < edge; i++){
            cin>>first>>second;
            a = getId(first);
            b = getId(second);
            graph[a][b] = '1';        //unweighted and bidirectional graph
            graph[b][a] = '1';
        }

        int n;

        cout<<"DATA SET  "<<cases++<<endl<<endl;

        for(int i = 0; i < request; i++){
            cin>>n>>first>>second;
            a = getId(first);
            b = getId(second);
            k = breadthFirst(a, b);

            if(k == -1){
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
            }
            else{
                int result = n * k * 100;
                cout<<"$"<<result<<endl;
            }
        }
        cout<<endl;
    }

    cout<<"END OF OUTPUT"<<endl;

    return 0;
}
