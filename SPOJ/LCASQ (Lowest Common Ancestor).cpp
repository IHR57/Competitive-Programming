#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define pb push_back
#define MAX 10005
using namespace std;

vector<int> tree[MAX];
int depth[MAX], T[MAX];
int parent[MAX][14];

void dfs(int from, int u, int dep)
{
    T[u] = from;
    depth[u] = dep;

    for(int i = 0; i < tree[u].size(); i++){
        int v = tree[u][i];
        if(v == from)
            continue;
        dfs(u, v, dep + 1);
    }
}

void LCAinit(int n)
{
    memset(parent, -1, sizeof(parent));

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

int LCAquery(int p, int q)
{
    if(depth[p] < depth[q])
        swap(p, q);

    int lg = 1;
    while(1){
        int next = lg + 1;
        if((1<<next) > depth[p]){
            break;
        }
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
    int test, caseNo = 1, nodeNo, child, u, v;

    //scanf("%d", &test);

   // while(test--){
        scanf("%d", &nodeNo);
        for(int i = 0; i < nodeNo; i++){
            scanf("%d", &child);
            while(child--){
                scanf("%d", &u);
                tree[i].pb(u);      //undirected
                tree[u].pb(i);
            }
        }

        dfs(0, 0, 0);
       // for(int i = 0; i < nodeNo; i++)
         //   cout<<depth[i]<<endl;
        LCAinit(nodeNo);

        int q;
        scanf("%d", &q);

        //printf("Case %d:\n", caseNo++);
        for(int i = 0; i < q; i++){
            scanf("%d %d", &u, &v);
            printf("%d\n", LCAquery(u, v));
        }

       // for(int i = 0; i < MAX; i++)
            //tree[i].clear();
    //}

    return 0;
}

