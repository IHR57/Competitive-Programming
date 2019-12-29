//Problem ID: CodeForces - 1098A (Sum in the Tree)
//Programmer: IQBAL HOSSAIN     Description: DFS/Graphs
//Date: 09/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
int parent[MAX], level[MAX], s[MAX], visited[MAX], opt[MAX];
vector<int> graph[MAX];
int flag;

ll ans;
const int inf = 2147483647;

void dfs(int u)
{
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            level[v] = level[u] + 1;
            if(level[v] % 2 == 0){
                int temp = opt[u];
                if(temp < s[parent[u]]){
                    flag = 1;
                    return;
                }
                else{
                    ans += 1LL * (s[v] - opt[u]);
                }
            }
            else{
                for(int j = 0; j < graph[v].size(); j++){
                    if(!visited[graph[v][j]])
                        opt[v] = min(opt[v], s[graph[v][j]]);
                }
            }
            dfs(v);
        }
    }
    if(level[u] % 2 == 1 && opt[u] != inf){
        ans += 1LL * (opt[u] - s[parent[u]]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, val;

    cin>>n;

    for(int i = 1; i <= n; i++)
        opt[i] = inf;

    parent[1] = -1, level[0] = 0;
    for(int i = 2; i <= n; i++){
        cin>>val;
        parent[i] = val;
        graph[i].push_back(val);
        graph[val].push_back(i);
    }

    for(int i = 1; i <= n; i++){
        cin>>s[i];
    }

    ans = (ll) s[1], flag = 0;
    dfs(1);
    if(flag){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;

    return 0;
}
