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

int depth[MAX], T[MAX];
int parent[MAX][20];
vi graph[MAX];

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
	for(int i = 1; i <= n; i++){
		parent[i][0] = T[i];
	}

	for(int j = 1; (1<<j) < n; j++){
		for(int i = 1; i <= n; i++){
			if(parent[i][j-1] != -1){
				parent[i][j] = parent[parent[i][j-1]][j-1];
			}
		}
	}
}

int lca(int p, int q)
{
	if(depth[p] < depth[q])
		swap(p, q);

	int lg = (int) log2(depth[p]) + 1;

	for(int i = lg; i >= 0; i--){
		if(depth[p] - (1<<i) >= depth[q]){
			p = parent[p][i];
		}
	}

	if(p == q)
		return p;

	for(int i = lg; i >= 0; i--){
		if(parent[p][i] != - 1 && parent[p][i] != parent[q][i]){
			p = parent[p][i];
			q = parent[q][i];
		}
	}

	return T[p];
}

int main()
{
	fastIO;
	//read; write;

	int n, query, a, b, c;

	cin>>n>>query;

	for(int i = 2; i <= n; i++){
		cin>>a;
		graph[a].pb(i);
		graph[i].pb(a);
	}

	mem(parent, -1);
	mem(T, -1);
	dfs(1, 1, 1);
	init(n);

	for(int i = 0; i < query; i++){
		cin>>a>>b>>c;
		if(a == b && b == c)
			cout<<1<<endl;
		else if(a == b){
			cout<<depth[a] + depth[c] - 2 * depth[lca(a, c)] + 1<<endl;
		}
		else if(a == c){
			cout<<depth[c] + depth[b] - 2 * depth[lca(c, b)] + 1<<endl;
		}
		else if(b == c){
			cout<<depth[b] + depth[a] - 2 * depth[lca(a, b)] + 1<<endl;
		}
		else{
			int l = lca(a, b);
			if(depth[lca(a, c)] > depth[l])
				l = lca(a, c);
			if(depth[lca(b, c)] > depth[l])
				l = lca (b, c);

			cout<<max(depth[a] + depth[l] - 2 * depth[lca(a, l)] + 1, max(depth[b] + depth[l] - 2 * depth[lca(b, l)] + 1, depth[c] + depth[l] - 2 * depth[lca(c, l)] + 1))<<endl;
		}
	}

	return 0;
}
