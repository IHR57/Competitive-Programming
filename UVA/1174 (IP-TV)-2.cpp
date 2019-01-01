#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#define MAX 50005
using namespace std;

struct Edge
{
    int u, v, w;
};

bool operator<(Edge A, Edge B)
{
    return A.w < B.w;
}

int parent[MAX];        //for storing representative
vector<Edge> e;     //creating a vector of edge

int findSet(int x)  //finding the representative of element x
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

int MST(int n)
{
    sort(e.begin(), e.end());

    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }

    int sz = e.size();
    int count = 0, ans = 0;

    for(int i = 0; i < sz; i++){
        int u = findSet(e[i].u);
        int v = findSet(e[i].v);

        if(u != v){     //if not in same set
            parent[u] = v;
            count++;
            ans += e[i].w;

            if(count == n-1)
                break;
        }
    }

    return ans;
}
int main()
{
    char first[50], second[50];      //for input two cities
    int test, m, n, u, v, cost;    //n = number of city; m = number of edge

    cin>>test;

    while(test--){
        cin>>n>>m;

        e.clear();      //clearing the vector

        map<string, int> M;
        int count = 0;
        for(int i = 0; i < m; i++){
            Edge get;
            cin>>first>>second>>cost;
            u = M[first];       //mapping string to integer
            v = M[second];

            if(u == 0){
                M[first] = ++count;
                u = count;
            }
            if(v == 0){
                M[second] = ++count;
                v = count;
            }
            get.u = u; get.v = v; get.w = cost;

            e.push_back(get);
        }

        cout<<MST(m)<<endl;

        if(test)
            cout<<endl;
    }

    return 0;
}
