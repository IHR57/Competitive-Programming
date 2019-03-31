//Problem ID: CodeForces - 744A (Hongcow Builds a Nation)
//Programmer: IQBAL HOSSAIN     Description: DFS
//Date: 26/03/19
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

const int inf = 1<<28;
typedef long long ll;
int govt[MAX], edgeCounter, visited[MAX];
vector<int> graph[MAX];

int dfs(int u)
{
    edgeCounter += graph[u].size();
    visited[u] = 1;
    int ret = 1;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            ret += dfs(v);
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k, u, v;

    cin>>n>>m>>k;
    for(int i = 0; i < k; i++){
        cin>>govt[i];
    }

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int m1 = -1, m2 = inf, res;
    int sum = 0, ans = 0;
    for(int i = 0; i < k; i++){
        edgeCounter = 0;
        res = dfs(govt[i]);
        sum += res;
        edgeCounter /= 2;
        ans += ((res * (res - 1)) >> 1) - edgeCounter;
        if(res > m1){
            m1 = res;
            m2 = edgeCounter;
        }
        if(res == m1){
            if(edgeCounter < m2){
                m2 = edgeCounter;
            }
        }

    }

    //cout<<ans<<endl;

    sum = n - sum + m1;
    ans += (sum * (sum - 1)) >> 1;
    ans -= (m1 * (m1 - 1)) >> 1;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            edgeCounter = 0;
            res = dfs(i);
            ans -= (edgeCounter / 2);
        }
    }

    cout<<ans<<endl;

    return 0;
}
