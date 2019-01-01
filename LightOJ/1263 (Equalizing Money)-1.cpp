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
int visited[MAX], sumNode[MAX], avg;

bool bfs(int source)
{
    int sum = 0;
    int cnt = 1;

    visited[source] = 1;
    sum += sumNode[source-1];
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                cnt++;
                sum += sumNode[v-1];
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    if(sum / cnt == avg)
        return true;

    return false;
}
int main()
{
    int test, caseNo = 1, data, sum, nodeNo, edgeNo, u, v, flag;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &nodeNo, &edgeNo);
        sum = 0, flag = 0;
        for(int i = 0; i < nodeNo; i++){
            scanf("%d", &sumNode[i]);
            sum += sumNode[i];
        }

        avg = sum / nodeNo;

        if(sum % nodeNo != 0)
            flag = 1;

        for(int i = 0; i < edgeNo; i++){
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        if(flag){
            printf("Case %d: No\n", caseNo++);
            continue;
        }

        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= nodeNo; i++){
            if(!visited[i]){
                bool t = bfs(i);
                if(!t){
                    flag = 1;
                    break;
                }
            }
        }

        if(!flag){
            printf("Case %d: Yes\n", caseNo++);
        }
        else
            printf("Case %d: No\n", caseNo++);

        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}
