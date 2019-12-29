#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

vector<int> graph[MAX];
int visited[MAX], color[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u, v;

    cin>>n;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int Max = -1;
    for(int i = 1; i <= n; i++){
        int sz = graph[i].size();
        if(sz > Max)
            Max = sz;
    }

    cout<<Max + 1<<endl;
    set<int> s;
    for(int i = 1; i <= Max + 1; i++){
        s.insert(i);
    }

    color[1] = 1;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        u = q.front();
        q.pop();

        int fst, snd = -1;
        fst = color[u];

        for(int i = 0; i < graph[u].size(); i++){
            if(color[graph[u][i]]){
                snd = color[graph[u][i]];
                break;
            }
        }
        s.erase(fst);
        if(snd != -1)
            s.erase(snd);

        set<int> :: iterator it;
        it = s.begin();
        for(int k = 0; k < graph[u].size(); k++){
            v = graph[u][k];
            if(!color[v]){
                color[v] = *it;
                q.push(v);
                it++;
            }
        }
        s.insert(fst);
        if(snd != -1)
            s.insert(snd);
    }

    for(int i = 1; i <= n; i++)
        cout<<color[i]<<" ";
    cout<<endl;


    return 0;
}
