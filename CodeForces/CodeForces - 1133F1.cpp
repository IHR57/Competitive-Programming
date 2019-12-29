//Problem ID: CodeForces - 1133F1 (Spanning Tree with Maximum Degree)
//Programmer: IQBAL HOSSAIN     Description: Graphs
//Date: 07/04/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

vector<int> graph[MAX];
int degree[MAX], visited[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, u, v;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int Max = -1, idx;
    for(int i = 1; i <= n; i++){
        if(degree[i] > Max){
            Max = degree[i];
            idx = i;
        }
    }

    queue<int> q;
    visited[idx] = 1;
    for(int i = 0; i < graph[idx].size(); i++){
        v = graph[idx][i];
        q.push(v);
        visited[v] = 1;
        cout<<idx<<" "<<v<<endl;
    }

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            v = graph[u][i];
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
                cout<<u<<" "<<v<<endl;
            }
        }
    }

    return 0;

}
