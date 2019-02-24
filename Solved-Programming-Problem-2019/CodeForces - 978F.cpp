//Problem ID: CodeForces - 978F (Mentors)
//Programmer: IQBAL HOSSAIN     Description: Graph
//Date: 24/02/19
#include <bits/stdc++.h>
#define MAX 200005
#define INF 2147483647
using namespace std;

vector<int> temp, graph[MAX], skill;
int visited[MAX], vis[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, u, v;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>u;
        skill.push_back(u);
    }
    for(int i = 0; i < k; i++){
        cin>>u>>v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    temp = skill;

    sort(temp.begin(), temp.end());

    for(int i =  0; i < n; i++){
        int ans = lower_bound(temp.begin(), temp.end(), skill[i]) - temp.begin();
        for(int j = 0; j < graph[i].size(); j++){
            v = graph[i][j];
            if(skill[v] < skill[i])
                ans--;
        }
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}
