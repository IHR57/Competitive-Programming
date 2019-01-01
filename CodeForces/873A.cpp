#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
#define MAX 100005
using namespace std;

vector<int> graph[10];
int cost[10][10];

int main()
{
    int n, a, b, c;

    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);
    graph[1].pb(2);
    graph[2].pb(1);
    graph[1].pb(3);
    graph[3].pb(1);
    graph[2].pb(3);
    graph[3].pb(2);
    cost[1][2] = a;
    cost[2][1] = a;
    cost[2][3] = c;
    cost[3][2] = c;
    cost[1][3] = b;
    cost[3][1] = b;

    queue<int> q;
    q.push(1);
    int ans = 0;

    for(int i = 1; i <= n - 1; i++){
        int u = q.front();
        q.pop();

        int v1 = graph[u][0];
        int v2 = graph[u][1];

        if(cost[u][v1] < cost[u][v2]){
            q.push(v1);
            ans += cost[u][v1];
        }
        else{
            q.push(v2);
            ans += cost[u][v2];
        }
    }

    printf("%d\n", ans);

    return 0;
}
