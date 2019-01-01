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


vector<pii> graph[MAX];
int parent[MAX][21], maxi[MAX][21], mini[MAX][21];
int T[MAX], depth[MAX], cost[MAX];
int Max, Min;

void dfs(int from, int u, int dep)
{
	T[u] = from;
	depth[u] = dep;

	for(int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i].first;
		int c = graph[u][i].second;
		if(v == from)
			continue;
		cost[v] = c;
		dfs(u, v, dep+1);
	}
}

void init(int n)		//initialize by sparse table
{
	for(int i = 0; i < n; i++){
		parent[i][0] = T[i];
		maxi[i][0] = cost[i];
		mini[i][0] = cost[i];
	}

	for(int i = 0; i < 21; i++){
        mini[0][i] = INF;
	}

	for(int j = 1; (1<<j) < n; j++){
		for(int i = 0; i < n; i++){
			if(parent[i][j-1] != -1){
				parent[i][j] = parent[parent[i][j-1]][j-1];
				maxi[i][j] = max(maxi[i][j-1], maxi[parent[i][j-1]][j-1]);
				mini[i][j] = min(mini[i][j-1], mini[parent[i][j-1]][j-1]);
			}
		}
	}
}

void MaxMinEdge(int p, int q)
{
	Max = -INF, Min = INF;

	if(depth[p] < depth[q])
		swap(p, q);

	int lg = (int) log2(depth[p]) + 1;

	for(int i = lg; i >= 0; i--){			//same level
        if(depth[p] - (1<<i) >= depth[q]){
            Max = max(Max, maxi[p][i]);
            Min = min(Min, mini[p][i]);
            p = parent[p][i];
        }
	}

	if(p == q)
		return;

	for(int i = lg; i >= 0; i--){
		if(parent[p][i] != -1 && parent[p][i] != parent[q][i]){
			Max = max(Max, max(maxi[p][i], maxi[q][i]));
			Min = min(Min, min(mini[p][i], mini[q][i]));
			p = parent[p][i];
			q = parent[q][i];
		}
	}

	Max = max(Max, max(cost[p], cost[q]));
	Min = min(Min, min(cost[p], cost[q]));
}

int main()
{
	//read; write;
	int test, n, q, u, v, w, caseNo = 1;

	//scanf("%d", &test);

	//while(test--){
		scanf("%d", &n);
		for(int i = 0; i < n - 1; i++){
			scanf("%d %d %d", &u, &v, &w);
			u--, v--;
			graph[u].pb(mp(v, w));
			graph[v].pb(mp(u, w));
		}

        mem(mini, 0);
		mem(maxi, 0);
		mem(T, -1);
		mem(parent, -1);
		mem(cost, 0);
		mem(depth, 0);

		dfs(0, 0, 0);
		init(n);

		//for(int i = 0; i < n; i++){
          //  cout<<cost[i]<<endl;
		//}

		scanf("%d", &q);

		//printf("Case %d:\n", caseNo++);
		for(int i = 0; i < q; i++){
			scanf("%d %d", &u, &v);
			u--, v--;
			MaxMinEdge(u, v);
			printf("%d %d\n", Min, Max);		//maximum and minimum edge on path u to v
		}

		for(int i = 0; i < MAX; i++)
            graph[i].clear();
	//}

	return 0;
}

