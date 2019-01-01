#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <list>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>
#include <stack>
#define MAX 5005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF 2147483647
#define mp make_pair
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector< vector<int> >vii;
typedef vector<double> vd;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;

vi graph[MAX];
int parent[MAX][20], T[MAX], depth[MAX];

void dfs(int from, int u, int dep)
{
    T[u] = from;
    depth[u] = dep;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == from)
            continue;
        dfs(u, v, dep + 1);
    }
}

void init(int n)
{
    T[0] = -1;
    for(int i = 0; i < n; i++){
        parent[i][0] = T[i];
    }

    for(int j = 1; (1<<j) < n; j++){
        for(int i = 0; i < n; i++){
            if(parent[i][j-1] != -1){
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
}

int lca(int p, int q)
{
    if(depth[p] < depth[q]){
        swap(p, q);
    }

    int lg = (int) log2(depth[p]) + 1;

    for(int i = lg; i >= 0; i--){
        if(depth[p] - (1<<i) >= depth[q]){
            p = parent[p][i];
        }
    }

    if(p == q)
        return p;

    for(int i = lg; i >= 0; i--){
        if(parent[p][i] != -1 && parent[p][i] != parent[q][i]){
            p = parent[p][i];
            q = parent[q][i];
        }
    }

    return T[p];
}

int kth(int p, int k)
{
    int sum = 0;
    int lg = (int) log2(k) + 1;

    for(int i = lg; i >= 0; i--){
        if(sum + (1<<i) <= k){
            sum += (1<<i);
            p = parent[p][i];
            if(sum == k){
                return p;
            }
        }
    }
}

int main()
{
    //read; write;
    int nodeNo, u, v, query, temp, ancestor, totalDepth;

    while(scanf("%d", &nodeNo) == 1){
        if(!nodeNo) break;
        for(int i = 0; i < nodeNo - 1; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            graph[u].pb(v);
            graph[v].pb(u);
        }

        mem(T, -1);
        mem(parent, -1);

        dfs(0, 0, 1);
        init(nodeNo);

        scanf("%d", &query);

        for(int i = 0; i < query; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            if(u == T[v] || v == T[u]){
                if(u < v)
                    printf("The fleas jump forever between %d and %d.\n", u + 1, v + 1);
                else{
                    printf("The fleas jump forever between %d and %d.\n", v + 1, u + 1);
                }
                continue;
            }
            else if(u == v){
                printf("The fleas meet at %d.\n", u + 1);
                continue;
            }

            if(depth[u] > depth[v])
                swap(u, v);
            ancestor = lca(u, v);
            totalDepth = depth[u] + depth[v] - 2 * depth[ancestor] + 1;
            if(totalDepth % 2 == 0){
                temp = kth(v, (totalDepth / 2) - 1);
                if(temp > T[temp])
                    printf("The fleas jump forever between %d and %d.\n", T[temp] + 1, temp + 1);
                else{
                    printf("The fleas jump forever between %d and %d.\n",temp + 1, T[temp] + 1);
                }
            }
            else{
                temp = kth(v, totalDepth / 2);
                printf("The fleas meet at %d.\n", temp + 1);
            }
        }

        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}
