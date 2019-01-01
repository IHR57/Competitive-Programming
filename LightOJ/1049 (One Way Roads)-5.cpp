#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 105
using namespace std;

typedef long long lint;

int graph[MAX][MAX], cost[MAX][MAX], visited[MAX];
int nodeNo;

int breadthFirst(int source)
{
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(source);
    visited[source] = 1;
    int sum = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 1; i <= nodeNo; i++){
            if(graph[u][i] == 1 && !visited[i]){
                visited[i] = 1;
                sum += cost[u][i];
                q.push(i);
            }
        }
    }

    return sum;
}

int main()
{
    int test, caseNo = 1, u, v, w;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &nodeNo);
        vector<int> src;
        for(int i = 0; i < MAX; i++){
                for(int j = 0; j < MAX; j++)
                    graph[i][j] = 0;
        }
        for(int i = 1; i <= nodeNo; i++){
            scanf("%d %d %d", &u, &v, &w);
            cost[u][v] = 0;
            cost[v][u] = w;     //reverse the cost

            //make the graph bi-directional though the problem statement tells it is a directed graph
            graph[u][v] = 1;
            graph[v][u] = 1;
            if(u == 1)
                src.push_back(v);
            else if(v == 1)
                src.push_back(u);
        }
        //the graph formed a ring so 1 is connected to two node
        //cout<<src[0]<<" "<<src[1]<<endl;
        graph[1][src[0]] = 0;            //disconnect first node
        graph[src[0]][1] = 0;

        int ans1 = breadthFirst(1) + cost[src[0]][1];        //run bfs
        //cout<<ans1<<endl;
        graph[1][src[0]] = 1;            //connect first node again
        graph[src[0]][1] = 1;
        graph[1][src[1]] = 0;        //disconnect second node
        graph[src[1]][1] = 0;
        int ans2 = breadthFirst(1) + cost[src[1]][1];
        //cout<<ans2<<endl;

        int result = min(ans1, ans2);

        printf("Case %d: %d\n", caseNo++, result);
        src.clear();
    }

    return 0;
}
