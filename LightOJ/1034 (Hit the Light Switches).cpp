#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

vector<int> graph[MAX];
int visited[MAX], finish[MAX], finishing_time;

int dfs(int n)          //this function will traverse graph and calculate finishing time
{
    finishing_time++;
    visited[n] = 1;

    for(int i = 0; i < graph[n].size(); i++){
        if(!visited[graph[n][i]]){
            dfs(graph[n][i]);
        }
    }

    finish[n] = ++finishing_time;

    return 0;
}

int dfs2(int n)
{
    visited[n] = 1;

    for(int i = 0; i < graph[n].size(); i++){
        if(!visited[graph[n][i]]){
            dfs2(graph[n][i]);
        }
    }

    return 0;
}

int main()
{
    int test, cases = 1, node, edge, a, b;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &node, &edge);
        while(edge--){
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
        }

        memset(visited, 0, sizeof(visited));
        finishing_time = 0;

        for(int i = 1; i <= node; i++){
            if(!visited[i])
                dfs(i);
        }
        /*for(int i = 1; i <= node; i++){
            cout<<i<<" = "<<finish[i]<<endl;
        }*/
        vector<pair<int, int> >v;

        for(int i = 1; i <= node; i++){
            v.push_back(make_pair(finish[i], i));
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());        //decreasing order

        memset(visited, 0, sizeof(visited));

        int count = 0;
        for(int i =  0; i < node; i++){
            int m = v[i].second;
            if(!visited[m]){
                count++;
                dfs2(m);
            }
        }

        printf("Case %d: %d\n", cases++, count);

        for(int i = 0; i <= node; i++){
            graph[i].clear();
        }
    }

    return 0;
}
