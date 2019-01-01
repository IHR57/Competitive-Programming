//Problem ID: UVA 11504 (Dominos)
//Programmer: IQBAL HOSSAIN     Description: SCC + Topological sort
//Date: 31-03-17
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
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

    for(int i = 0; i < graph[n].size(); i++){
        if(!visited[graph[n][i]])
            dfs2(graph[n][i]);
    }
}
int main()
{
    int test, node, edge, a, b;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &node, &edge);
        while(edge--){
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
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

        printf("%d\n", count);

        for(int i = 0; i <= node; i++){
            graph[i].clear();
        }
    }

    return 0;
}
