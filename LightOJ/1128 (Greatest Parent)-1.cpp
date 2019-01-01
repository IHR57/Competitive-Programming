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

int parent[MAX][21], T[MAX], cost[MAX];

void init(int n)
{
	for(int i = 0; i < n; i++){
		parent[i][0] = T[i];
	}

	for(int j = 1; (1 << j) < n; j++){
		for(int i = 0; i < n; i++){
			if(parent[i][j-1] != -1){
				parent[i][j] = parent[parent[i][j-1]][j-1];
			}
		}
	}
}

int query(int p, int val, int n)
{
	int lg = (int) log2(n) + 1;

	for(int i = lg; i >= 0; i--){
		if(parent[p][i] != -1 && cost[parent[p][i]] >= val){
			p = parent[p][i];
		}
	}

	return p;
}

int main()
{
	//read; write;
	int test, caseNo = 1, u, v, q, n;

	scanf("%d", &test);

	while(test--){
		T[0] = -1, cost[0] = 1;			//parent and cost of the root node
		scanf("%d %d", &n, &q);		//number of node and query
		for(int i = 1; i <= n - 1; i++){
			scanf("%d %d", &u, &v);
			T[i] = u;		//parent
			cost[i] = v;		//cost of this node
		}

		mem(parent, -1);
		init(n);

        printf("Case %d:\n", caseNo++);

		for(int i = 0; i < q; i++){
			scanf("%d %d", &u, &v);
			printf("%d\n", query(u, v, n));
		}
	}

	return 0;
}
