#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int parent[MAX], Rank[MAX];
int numofDisjoint;      //counting number of disjoint set

struct Edge
{
    int u, v, cost;
};

bool operator<(Edge A, Edge B)
{
    return A.cost < B.cost;
}

int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

vector<Edge> e;

int main()
{
    int test, a, b, amount, cases = 1, n, m, cost;

    cin>>test;

    while(test--){
        e.clear();          //clearing previously stored element
        cin>>n>>m>>amount;

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }

        for(int i = 0; i < m; i++){
            cin>>a>>b>>cost;
            Edge get;
            get.u = a; get.v = b; get.cost = cost;
                e.push_back(get);
        }
        sort(e.begin(), e.end());
        int sz = e.size();
        int ans = 0, airport = 0;

        for(int i = 0; i < sz; i++){
            int u = findSet(e[i].u);
            int v = findSet(e[i].v);
            int w = e[i].cost;

            if(u != v){
                parent[u] = v;
                if(w >= amount){
                    airport++;
                    ans += amount;
                }
                else
                    ans += w;
            }
        }

        memset(Rank, 0, sizeof(Rank));

        for(int i = 1; i <= n; i++){
            parent[i] = findSet(i);
            Rank[parent[i]]++;
        }

        for(int i = 1; i <= n; i++){
            if(Rank[i]){
                airport++;
                ans += amount;
            }
        }

        cout<<"Case #"<<cases++<<": "<<ans<<" "<<airport<<endl;
    }

    return 0;
}
