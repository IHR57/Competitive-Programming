#include <bits/stdc++.h>
#define MAX 105
using namespace std;

vector<int> graph[MAX];
vector<int>ts;
int dfs_num[MAX];

void depthFirst(int u)
{
    if(dfs_num[u])
        return;
    dfs_num[u] = 1;         //make source visited

    for(int i = 0; i < graph[u].size(); i++){
        if(dfs_num[graph[u][i]] == 0){
            depthFirst(graph[u][i]);
        }
    }

    ts.push_back(u);
}

int main()
{
    int node, edge, a, b;

    while(scanf("%d %d", &node, &edge) == 2){
        if(node == 0 && edge == 0)
            break;
        ts.clear();
        //graph.assign(node, vi());
        for(int i = 0; i < edge; i++){
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
        }

        for(int i = 1; i <= node; i++){
            dfs_num[i] = 0;     //initialize all node are unvisited
        }

        for(int i = 1; i <= node; i++){
            if(dfs_num[i] == 0){        //if node is  unvisited
                depthFirst(i);
            }
        }

        int sz = ts.size();
        //cout<<"Size: "<<sz<<endl;

        for(int i = sz - 1; i >= 0; i--){       //print in reverse order
            printf("%d ", ts[i]);
        }
        printf("\n");
    }

    return 0;
}
