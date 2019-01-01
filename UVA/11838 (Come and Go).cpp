#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

vector<int> graph[MAX], revGraph[MAX];
int visited[MAX], finishing_time, finish[MAX];

int dfs(int n)
{
    finishing_time++;       //increment finishing_time
    visited[n] = 1;         //make this node visited

    for(int i = 0; i < graph[n].size(); i++){
        if(!visited[graph[n][i]]){
            dfs(graph[n][i]);
        }
    }

    finish[n] = ++finishing_time;       //we just need finishing time

    return 0;
}

int dfs2(int n)
{
    visited[n] = 1;

    for(int i = 0; i < revGraph[n].size(); i++){
        if(!visited[revGraph[n][i]])
            dfs2(revGraph[n][i]);
    }
}
int main()
{
    int test, node, edge, a, b, p;

    //scanf("%d", &test);

    while(scanf("%d %d", &node, &edge) == 2){
        if(!node && !edge)
            break;
        while(edge--){
            scanf("%d %d %d", &a, &b, &p);
            if(p == 1){
                graph[a].push_back(b);
                revGraph[b].push_back(a);
            }
            else{
                graph[a].push_back(b);
                revGraph[b].push_back(a);
                graph[b].push_back(a);
                revGraph[a].push_back(b);
            }
        }

        memset(visited, 0, sizeof(visited));    //make all the node unvisited
        finishing_time = 0;     //initialize finishing_time

        for(int i = 1; i <= node; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        vector<pair<int, int> > v;

        for(int i = 1; i <= node; i++){
            v.push_back(make_pair(finish[i], i));
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());        //sort in decreasing order

        memset(visited, 0, sizeof(visited));        //again make all the node unvisited

        int count = 0;
        for(int i = 0; i < node; i++){
            int m = v[i].second;
            if(!visited[m]){
                count++;        //count number of SCC
                dfs2(m);
            }
        }

        if(count == 1){
            printf("1\n");
        }
        else
            printf("0\n");

        for(int i = 0; i <= node; i++){
            graph[i].clear();
            revGraph[i].clear();
        }
    }

    return 0;
}
