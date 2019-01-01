//Problem ID: UVA 10959 (The Party, Part I)
//Programmer: IQBAL HOSSAIN     Description: Single Source Shortest Path (Graph: BFS)
//Date: 21-02-16
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#define MAX 1005
using namespace std;

char graph[MAX][MAX];
int dist[MAX];
char color[MAX];
int nodeCounter;        //for counting node

const int INF = 1 << 28;        //define infinity

void init()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            graph[i][j] = '0';
        }
    }
}

//this function will return the  distance from source node
void BreadthFirstSearch(int source)
{
    for(int i = 0; i < MAX; i++){
        dist[i] = INF;
        color[i] = 'w';         //set initial colour and distance;
    }

    queue<int>q;

    dist[source] = 0;
    color[source] = 'g';

    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i <= nodeCounter; i++){
            if(graph[u][i] == '1' && color[i] == 'w'){
                color[i] = 'g';
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }

        color[u] = 'b';
    }

    //return dist[destination];
}

int main()
{
    int test, vertices, edges;
    int a, b;

    cin>>test;

    while(test--){
        cin>>vertices>>edges;

        init();
        nodeCounter = vertices - 1;
        for(int i = 0; i < edges; i++){
            cin>>a>>b;
            graph[a][b] = '1';
            graph[b][a] = '1';      //connecting the graph
        }

        BreadthFirstSearch(0);

        for(int i = 1; i < vertices; i++){
            cout<<dist[i]<<endl;
        }

        if(test)
            cout<<endl;
    }

    return 0;
}
