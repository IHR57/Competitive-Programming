#include <bits/stdc++.h>
#define MAX 1000002
using namespace std;

int in_degree[MAX];
vector<int> graph[MAX];
vector<int>topsort_order;

int main()
{
    int node, edge, a, b;

    while(scanf("%d %d", &node, &edge) == 2){
        if(!node && !edge)
            break;

        //memset(in_degree, 0, sizeof(in_degree));

        for(int i = 0; i < edge; i++){
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            in_degree[b]++;
        }

        queue<int>q;

        for(int i = 1; i <= node; i++){
            if(in_degree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            topsort_order.push_back(u);

            for(int i = 0; i < graph[u].size(); i++){
                in_degree[graph[u][i]]--;
                if(in_degree[graph[u][i]] == 0)
                    q.push(graph[u][i]);
            }
            count++;
        }

        if(count == node){
            for(int i = 0; i < topsort_order.size(); i++){
                printf("%d\n", topsort_order[i]);
            }
        }
        else
            printf("IMPOSSIBLE\n");

        for(int i = 1; i <= node; i++){
            graph[i].clear();
            in_degree[i] = 0;
        }
        topsort_order.clear();
    }

    return 0;
}
