//Depth First Search
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

vector<int> matrix[100];
int visited[100];
int Print[100];

void dfs(int source)
{
    if(visited[source])
        return;
    visited[source] = 1;

    for(int i = 0; i < matrix[source].size(); i++){
        if(!Print[matrix[source][i]]){
            cout<<matrix[source][i]<<"->";
            Print[matrix[source][i]] = 1;
        }
        dfs(matrix[source][i]);
    }
}

int main()
{
    int node, edges, a, b;

    while(cin>>node>>edges){
        if(node == 0 && edge == 0)
            break;
        for(int i = 0; i < edges; i++){
            cin>>a>>b;
            matrix[a].push_back(b);
            matrix[b].push_back(a);
        }

        for(int i = 0; i < 100; i++){
            visited[i] = 0;
            Print[i] = 0;
        }

        cout<<"Enter source node: ";
        int source;

        cin>>source;

        dfs(source);
    }

    return 0;
}
