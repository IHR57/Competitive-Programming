#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];

int visited[MAX];
double par[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int u, v, n;

    cin>>n;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    par[1] = 1.0;
    double sum = 0.0;

    while(!q.empty()){
        u = q.front();
        q.pop();

        int sz = graph[u].size();
        int cnt = 0;
        vector<int> t;
        for(int i = 0; i < sz; i++){
            v = graph[u][i];
            if(!visited[v]){
                t.push_back(v);
                q.push(v);
                cnt++;
            }
        }

        double temp = par[u] / (double) cnt;

        for(int i = 0; i < t.size(); i++){
            visited[t[i]] = 1;
            sum += temp;
            par[t[i]] = temp;
        }
        t.clear();
    }

    cout<<setiosflags(ios::fixed)<<setprecision(8);
    cout<<sum<<endl;

    return 0;
}
