#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define pb push_back
#define MAX 1005
using namespace std;

typedef long long lint;
vector<int> graph[MAX];
int visited[MAX], nodeCounter[MAX];

void breadthFirst(int source)
{
    memset(visited, 0, sizeof(visited));

    visited[source] = 1;
    nodeCounter[source]++;
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = 1;
                nodeCounter[v]++;
                q.push(v);
            }
        }
    }
}
int main()
{
    int test, caseNo = 1, peopleNo, nodeNo, edgeNo, people[110];
    int u, v;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &peopleNo, &nodeNo, &edgeNo);
        for(int i = 0; i < peopleNo; i++)
            scanf("%d", &people[i]);
        for(int i = 0; i < edgeNo; i++){
            scanf("%d %d", &u, &v);
            graph[u].pb(v);             //directed graph
        }

        for(int i = 0 ; i < MAX; i++)
            nodeCounter[i] = 0;

        for(int i = 0; i < peopleNo; i++){
            breadthFirst(people[i]);
        }

        int count = 0;

        for(int i = 1; i <= nodeNo; i++){
            //cout<<i<<": "<<nodeCounter[i]<<endl;
            if(nodeCounter[i] == peopleNo)
                count++;
        }

        printf("Case %d: %d\n", caseNo++, count);

        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}
