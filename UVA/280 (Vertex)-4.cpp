#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 105
using namespace std;

vector<int> graph[MAX];
int visited[MAX];

void breadthFirst(int source)
{
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            if(visited[graph[u][i]])
                continue;
            visited[graph[u][i]] = 1;
            q.push(graph[u][i]);
        }
    }
}

int main()
{
    int first, second, query, q, n;

    while(cin>>n){
        if(n == 0)
            break;
        while(cin>>first){
            if(first == 0)
                break;
            while(cin>>second){
                if(second == 0)
                    break;
                graph[first-1].push_back(second-1);
            }
        }

        cin>>query;

        while(query--){
            cin>>q;

            for(int i = 0; i < n; i++){
                visited[i] = 0;
            }

            breadthFirst(q-1);

            //cout<<n - ans<<" ";

            int count = 0;
            for(int i = 0; i < n; i++){
                if(!visited[i])
                    count++;
            }

            cout<<count;
            for(int i = 0; i < n; i++){
                if(!visited[i])
                    cout<<" "<<i+1;
            }
            cout<<endl;
        }

        for(int i= 0; i < n; i++)
            graph[i].clear();

    }

    return 0;
}
