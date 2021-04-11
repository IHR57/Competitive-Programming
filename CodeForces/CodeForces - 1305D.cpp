//Date: 04/03/2020
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 1005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

set<int> graph[MAX];
set<int> leaf;

void dfs(int u, int par, int x)
{
    if(leaf.count(u))
        leaf.erase(u);

    for(set<int> :: iterator it = graph[u].begin(); it != graph[u].end(); it++){
        int v = *it;
        if(v == par)
            continue;
        if(v == x){
            graph[v].erase(u);
        }
        else if(graph[v].size())
            dfs(v, u, x);
    }

    graph[u].clear();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    for(int i = 1; i <= n; i++){
        if(graph[i].size() == 1){
            leaf.insert(i);
        }
    }

    int x, root, flag = 0;

    while(leaf.size() > 1){
        int u = *leaf.begin();
        leaf.erase(u);
        int v=  *leaf.begin();
        leaf.erase(v);

        cout<<"? "<<u<<" "<<v<<endl;
        cout.flush();

        cin>>x;

        if(x == u || x == v){
            cout<<"! "<<x<<endl;
            return 0;
        }

        dfs(u, -1, x);
        dfs(v, -1, x);

        if(graph[x].size() <= 1)
            leaf.insert(x);
    }

    cout<<"! "<<*leaf.begin()<<endl;

    return 0;
}
