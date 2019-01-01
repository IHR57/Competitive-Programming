//Problem ID: SPOJ QTREE2 (Query on a Tree II)
//Programmer: IQBAL HOSSAIN     Description: LCA
//Date: 26-12-17
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
#define MAX 100005
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

int depth[MAX], T[MAX], cost[MAX];
int parent[MAX][20], dist[MAX][20];
vector<pii> graph[MAX];
int ancestor;

void dfs(int from, int u, int dep)
{
    depth[u] = dep;
    T[u] = from;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i].first;
        int c = graph[u][i].second;
        if(v == from)
            continue;
        cost[v] = c;
        dfs(u, v, dep + 1);
    }
}

void init(int n)
{
    T[0] = -1;
    for(int i = 0; i < n; i++){
        parent[i][0] = T[i];
        dist[i][0] = cost[i];
    }

    for(int j = 1; (1<<j) < n; j++){
        for(int i = 0; i < n; i++){
            if(parent[i][j-1] != -1){
                parent[i][j] = parent[parent[i][j-1]][j-1];
                dist[i][j] = dist[i][j-1] + dist[parent[i][j-1]][j-1];
            }
        }
    }
}

ll totalCost(int p, int q)
{
    ll sum = 0;

    if(depth[p] < depth[q])
        swap(p, q);

    int lg = (int) log2(depth[p]) + 1;

    for(int i = lg; i >= 0; i--){
        if(depth[p] - (1<<i) >= depth[q]){
            sum += (ll) dist[p][i];
            p = parent[p][i];
        }
    }

    if(p == q){
        ancestor = p;
        return sum;
    }
    for(int i = lg; i >= 0; i--){
        if(parent[p][i] != -1 && parent[p][i] != parent[q][i]){
            sum += (ll) (dist[p][i] + dist[q][i]);
            p = parent[p][i];
            q = parent[q][i];
        }
    }

    sum += (ll) (cost[p] + cost[q]);
    ancestor = T[p];

    return sum;
}

int kthNode(int p, int k, int n)        //k'th node between the given path
{
    int lg = (int) log2(k) + 1;

    int sum = 0;
    for(int i = lg; i >= 0; i--){
        if((sum + (1<<i)) <= k){
            sum += (1<<i);
            p = parent[p][i];
            if(sum == k){
                //cout<<sum<<" "<<p<<endl;
                return p;
            }
        }
    }
}

int main()
{
	//read; write;
	int test, nodeNo, u, v, c, k;
	char str[100];

	scanf("%d", &test);

    while(test--){
        scanf("%d", &nodeNo);
        for(int i = 0; i < nodeNo - 1; i++){
            scanf("%d %d %d", &u, &v, &c);
            u--, v--;
            graph[u].pb(mp(v, c));
            graph[v].pb(mp(u, c));
        }

        mem(cost, 0);

        dfs(0, 0, 1);

        mem(parent, -1);
        mem(dist, -1);

        init(nodeNo);

        while(scanf("%s", str)){
            if(strcmp(str, "DONE") == 0){
                break;
            }
            if(strcmp(str, "DIST") == 0){
                scanf("%d %d", &u, &v);
                u--, v--;
                printf("%lld\n", totalCost(u, v));
            }
            else{
                scanf("%d %d %d", &u, &v, &k);
                u--, v--;
                ll result = totalCost(u, v);
                int l = depth[u] - depth[ancestor] + 1;     //distance ancestor to u
                int r = depth[v] - depth[ancestor] + 1;     //distance ancestor to v
                if(k == 1){             //special case
                    printf("%d\n", u + 1);
                }
                else if(k <= l){            //we need to check left part of ancestor (including ancestor)
                    printf("%d\n", kthNode(u, k - 1, nodeNo) + 1);
                }
                else{           //we need to check right part (including ancestor)
                    int temp = l + r - k - 1;
                    if(temp == 0){          //special case
                        printf("%d\n", v+1);
                    }
                    else
                        printf("%d\n", kthNode(v, temp, nodeNo) + 1);
                }
            }
        }
        printf("\n");
        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

	return 0;
}
