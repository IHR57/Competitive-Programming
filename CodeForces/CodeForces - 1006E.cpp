//Problem ID: CodeForces - 1006E (Military Problem)
//Programmer: IQBAL HOSSAIN     Description: DFS
//Date: 23/04/19
#include <bits/stdc++.h>
#define MAX 200005
#define pb push_back
using namespace std;

vector<int> res;
vector<int> graph[MAX];
int Size[MAX], idx[MAX];

void dfs(int u, int par)
{
    res.pb(u);
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par)
            continue;
        dfs(v, u);
        Size[u] += Size[v];
    }

    Size[u] += 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, k, u;

    cin>>n>>q;
    for(int i = 2; i <= n; i++){
        cin>>k;
        graph[k].pb(i);
    }

    dfs(1, -1);

    for(int i = 0; i < res.size(); i++){
        idx[res[i]] = i;
    }

    for(int i = 0; i < q; i++){
        cin>>u>>k;
        k--;
        if(idx[u] + k >= idx[u] + Size[u]){
            cout<<-1<<endl;
        }
        else{
            cout<<res[idx[u] + k]<<endl;
        }
    }


    return 0;
}
