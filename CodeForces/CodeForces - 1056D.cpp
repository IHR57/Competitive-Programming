//Problem ID: CodeForces - 1056D (Decorate Apple Tree)
//Programmer: IQBAL HOSSAIN     Description: DFS
//Date: 14/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int child[MAX];

vector<int> graph[MAX];

void dfs(int u)
{
    if(graph[u].size() == 0){
        child[u] = 1;
    }
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        dfs(v);
        child[u] += child[v];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, v;

    cin>>n;

    for(int i = 2; i <= n; i++){
        cin>>v;
        graph[v].push_back(i);
    }
    dfs(1);

   sort(child + 1, child + n + 1);

   for(int i = 1; i <= n; i++){
       cout<<child[i]<<" ";
   }
   cout<<endl;

    return 0;
}
