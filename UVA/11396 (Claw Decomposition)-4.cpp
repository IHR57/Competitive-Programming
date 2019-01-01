#include <bits/stdc++.h>
#define MAX 305
using namespace std;

typedef vector<int> vi;

int main()
{
    int node, u, v;
    vector<vi> graph;

    while(cin>>node){
        if(!node)
            break;
        graph.assign(node, vi());
        while(cin>>u>>v){
            if(u == 0 && v == 0)
                break;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);      //bi directional graph
        }

        vi color(node, 1e9);

        queue<int> q;
        q.push(0);
        color[0] = 0;
        //visited[source] = 1;

        bool isBipartite = true;
        while(!q.empty() && isBipartite){
            int u = q.front();
            q.pop();

            for(int i = 0; i < (int) graph[u].size(); i++){
                int v = graph[u][i];
                if(color[v] == 1e9){
                    color[v] = 1 - color[u];
                    //visited[graph[u][i]] = 1;
                    q.push(v);
                }
                else if(color[v] == color[u]){
                    isBipartite = false;
                    break;
                }
            }
        }

        if(isBipartite)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
