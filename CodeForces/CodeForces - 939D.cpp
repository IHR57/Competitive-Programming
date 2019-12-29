//Problem ID: CodeForces - 939D (Love Rescue)
//Programmer: IQBAL HOSSAIN     Description: DFS/DSU/Graphs/Greedy
//Date: 29/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

string str1, str2;

typedef pair<int, int> pii;
vector<int> graph[50];
int vis[50], visited[50];
vector<pii> ans;

void dfs(int u)
{
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            ans.push_back(make_pair(u, v));
            dfs(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    cin>>str1;
    cin>>str2;

    for(int i = 0; i < n; i++){
        if(str1[i] != str2[i]){
            graph[str1[i]-'a'].push_back(str2[i]-'a');
            graph[str2[i]-'a'].push_back(str1[i]-'a');
            vis[str1[i]-'a'] = vis[str2[i]-'a'] = 1;
        }
    }

    for(int i = 0; i < 26; i++){
        if(vis[i] && !visited[i]){
            dfs(i);
        }
    }

    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<char(ans[i].first + 97)<<" "<<char(ans[i].second + 97)<<endl;
    }

    return 0;
}
