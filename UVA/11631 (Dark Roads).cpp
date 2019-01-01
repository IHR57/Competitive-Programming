#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200005
using namespace std;

struct Edge
{
    int u, v, length;
};

bool operator<(Edge A, Edge B)
{
    return A.length < B.length;
}

vector<Edge> e;

int parent[MAX];

int findSet(int x)      //find the representative of x
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

int MinimumSpanningTree(int n)
{
    sort(e.begin(), e.end());       //sort the edge according minimum length

    for(int i = 0; i <= n; i++){        //initialize
        parent[i] = i;
    }

    int sz = e.size();      //total number of edge;

    int count = 0, ans = 0;

    for(int i = 0; i < sz; i++){
        int u = findSet(e[i].u);        //find the parent of u and v
        int v = findSet(e[i].v);

        if(u != v){     //if they are not in same set
            parent[u] = v;
            ans += e[i].length;
            count++;

            if(count == n-1)
                break;
        }
    }

    return ans;     //return the total cost of MST
}

int main()
{
    int n, m, cost, a, b, total;

    while(cin>>n>>m){
        if(n == 0 && m == 0)
            break;
        e.clear();      //clearing previously stored element
        total = 0;
        for(int i = 0; i < m; i++){
            cin>>a>>b>>cost;
            Edge get;
            get.u = a; get.v = b; get.length = cost;

            total += cost;      //total cost
            e.push_back(get);       //pushing the edge
        }

        int value = MinimumSpanningTree(n);     //cost of minimum spanning tree

        cout<<total - value<<endl;      //saved money
    }

    return 0;
}
