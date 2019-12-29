#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

struct Node
{
    int x, y;
};
bool compare(Node A, Node B)
{
    if(A.x == B.x)
        return A.y < B.y;
    return A.x < B.x;
}

set<int> s;
vector<int> graph[MAX], ans;
int visited[MAX];

//void dfs(int source)
//{
//    visited[source] = 1;
//    ans.push_back(source);
//
//    for(int i = 0; i < graph[source].size(); i++){
//        int v = graph[source][i];
//        if(!visited[v]){
//            dfs(v);
//        }
//    }
//}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, u, v;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source = 1;
    while(true){
        visited[source] = 1;
        ans.push_back(source);

        if(ans.size() == n)
            break;
        for(int i = 0 ; i < graph[source].size(); i++){
            v = graph[source][i];
            if(!visited[v]){
                s.insert(v);
            }
        }
        source = *s.begin();
        s.erase(source);
    }

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
