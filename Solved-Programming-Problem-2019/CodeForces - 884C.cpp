#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

vector<int> graph[MAX];
int cnt, visited[MAX];
bool hasCycle;

void dfs(int u)
{
    visited[u] = 1;
    cnt++;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, v;

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>v;
        graph[i].push_back(v);
    }

    priority_queue<int> pq;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt = 0;
            dfs(i);
            pq.push(cnt);
        }
    }

    ll ans = 1;
    if(pq.size() == 1){
        ans = ((ll) n * (ll) n);
    }
    else{
        ll fst = (ll) pq.top();
        pq.pop();
        ll snd = (ll) pq.top();
        pq.pop();

        ans = (fst + snd) * (fst + snd);
        while(!pq.empty()){
            ans += (pq.top() * pq.top());
            pq.pop();
        }
    }


    cout<<ans<<endl;

    return 0;
}
