#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define MAX 20005
using namespace std;

vector<int> graph[MAX];
int visited[MAX], result;
char color[MAX];

void bfs(int source, int n)
{
    for(int i = 0; i < n; i++){
        color[i] = 'w';
    }
    visited[source] = 1;
    color[source] = 'l';

    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v] && color[v] == 'w'){
                visited[v] = 1;
                if(color[u] == 'l')
                    color[v] = 'v';
                else if(color[u] == 'v')
                    color[v] = 'l';
                q.push(v);
            }
        }
    }

    int lykan = 0, vampire = 0;
    for(int i = 0; i < n; i++){
        if(color[i] == 'l')
            lykan++;
        else if(color[i] == 'v')
            vampire++;
    }

    result += max(lykan, vampire);
}

int main()
{
    int test, n, u, v, cases = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        map<int, int> myMap;
        int value = 0;

        while(n--){
            scanf("%d %d", &u, &v);
            if(myMap.find(u) == myMap.end())
                myMap[u] = value++;
            if(myMap.find(v) == myMap.end())
                myMap[v] = value++;
            int a = myMap[u];
            int b = myMap[v];
            graph[a].push_back(b);
            graph[b].push_back(a);

        }

        memset(visited, 0, sizeof(visited));

        result = 0;
        for(int i = 0; i < value; i++){
            if(!visited[i]){
                bfs(i, value);
            }
        }

        printf("Case %d: %d\n", cases++, result);

        for(int i = 0; i < value; i++)
            graph[i].clear();
    }

    return 0;
}
