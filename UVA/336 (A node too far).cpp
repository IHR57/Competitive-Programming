#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 100
using namespace std;

const int INF = 1<<28;

int graph[MAX][MAX], dist[MAX], id[MAX], nodeCounter;
char color[MAX];

void initialize()       //initialize all index to zero
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            graph[i][j] = 0;
        }
    }
}

int getId(int x)        //get the id number
{
    for(int i = 0; i < nodeCounter; i++){
        if(id[i] == x)      //if the id exists
            return i;
    }

    id[nodeCounter] = x;

    return nodeCounter++;
}

void breadthFirst(int source)
{
    for(int i = 0; i < MAX; i++){       //initialization
        dist[i] = INF;
        color[i] = 'w';     //set all the colour is w (white) i.e. not visited
    }

    queue<int> q;

    color[source] = 'g';        //if we visit a node
    dist[source] = 0;       //the distance of source node
    q.push(source);             //push the current working node

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < nodeCounter; i++){
            if(graph[u][i] == 1 && color[i] == 'w'){
                color[i] = 'g';
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }

        color[u] = 'b';
    }

}

int main()
{
    int edge, a, b, x, y, count, cases = 1;

    while(scanf("%d", &edge))
    {
        if(edge == 0)
            break;
        nodeCounter = 0;
        initialize();

        for(int i = 0; i < edge; i++){
            scanf("%d %d", &a, &b);         //input connection

            a = getId(a);       //mapping the id
            b = getId(b);

            graph[a][b] = 1;
            graph[b][a] = 1;        //the graph is bidirectional
        }

        while(scanf("%d %d", &x, &y) == 2){
            if(x == 0 && y == 0)
                break;
            int i = getId(x);       //source node
            breadthFirst(i);
            count = 0;

            for(int i = 0; i < nodeCounter; i++){
                if(dist[i] > y){
                    count++;
                }
            }

            printf("Case %d: ", cases++);
            printf("%d nodes not reachable from node %d with TTL = %d.\n", count, x, y);
        }
    }

    return 0;
}
