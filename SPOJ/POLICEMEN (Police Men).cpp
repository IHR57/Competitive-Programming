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
#define MAX 10005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define MOD 10000000007
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
int depth[MAX], parent[MAX][18], T[MAX];

void dfs(int from, int u, int dep)
{
    T[u] = from;
    depth[u] = dep;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == from)
            continue;
        dfs(u, v, dep+1);
    }
}

void init(int n)
{
    mem(parent, -1);
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

int query(int p, int q)
{
    if(depth[p] < depth[q])
        return -1;

    int lg = 1;
    while(1){
        int next = lg + 1;
        if((1 << next) > depth[p])
            break;
        lg++;
    }

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

int main()
{
    //read; write;
    int nodeNo, u, v, q;

    scanf("%d", &nodeNo);

    for(int i = 0; i < nodeNo - 1; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(0, 0, 0);
    init(nodeNo);

    scanf("%d", &q);

    while(q--){
        scanf("%d %d", &u, &v);
        u--, v--;
        int result = query(u, v);
        if(result == -1)
            printf("NO\n");
        else{
            printf("YES %d\n", result+ 1);
        }
    }

    return 0;
}
