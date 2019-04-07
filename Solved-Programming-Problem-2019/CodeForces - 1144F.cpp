//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef  pair<int, int> pii;
bool flag = false;
int color[MAX], visited[MAX];

vector<pii> vp;
vector<int> graph[MAX];

void dfs(int u, int c)
{
    color[u] = c;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(color[v] == -1){
            dfs(v, !c);
        }
        if(color[v] == c){
            flag = true;
            return;
        }

    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, u, v;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        vp.push_back(make_pair(u, v));
    }

    memset(color, -1, sizeof(color));
    dfs(1, 0);

    if(flag){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    for(int i = 0; i < vp.size(); i++){
        if(color[vp[i].first] == 0 && color[vp[i].second] == 1){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    cout<<endl;

    return 0;
}


