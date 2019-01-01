#include <bits/stdc++.h>
#define MAX 255
using namespace std;

int parent[MAX];

int findSet(int v)
{
    if(parent[v] < 0)
        return v;
    return parent[v] = findSet(parent[v]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, u, v, ans = 0;

    cin>>n>>m;

    memset(parent, -1, sizeof(parent));

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        u = findSet(u);
        v = findSet(v);
        if(u == v && (-parent[u]) % 2){
            ans++;
        }
        else{
            parent[u] += parent[v];
            parent[v] = u;
        }
    }

    if((n - ans) % 2)
        ans++;

    cout<<ans<<endl;

    return 0;
}
