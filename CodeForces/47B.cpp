#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[5], ts;
int visited[5];
bool cycle;

void dfs(int u)
{
    if(visited[u] == 0){
        visited[u] = 1;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            dfs(v);
        }
        visited[u] = 2;
        ts.push_back(u);
    }
    else if(visited[u] == 1)
        cycle = true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    for(int i = 0; i < 3; i++){
        cin>>str;
        int u = str[0] - 'A';
        int v = str[2] - 'A';
        if(str[1] == '>'){
            graph[v].push_back(u);
        }
        else if(str[1] == '<')
            graph[u].push_back(v);
    }

    for(int i = 0; i < 3; i++){
        if(cycle){
            cout<<"Impossible"<<endl;
            return 0;
        }
        dfs(i);
    }
    if(cycle){
        cout<<"Impossible"<<endl;
        return 0;
    }

    for(int i = ts.size() - 1; i >= 0; i--){
        char ch = ts[i] + 65;
        cout<<ch;
    }
    cout<<endl;

    return 0;
}
