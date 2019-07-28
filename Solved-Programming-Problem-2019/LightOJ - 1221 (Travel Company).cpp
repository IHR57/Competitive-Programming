//Problem ID: LightOJ - 1221 (Travel Company)
//Programmer: IQBAL HOSSAIN 	Description: Graph Theory (Floyd Warshall)
//Date: 22/07/19
#include <bits/stdc++.h>
#define MAX 105
#define pb push_back
#define INF 2147483647
#define MOD 1000000007
#define EPS 1e-7
using namespace std;

typedef long long ll;
int n, r, p;
const int inf = 1<<28;

int cost[MAX][MAX];

void init()
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cost[i][j] = inf;
		}
		cost[i][i] = 0;
	}
}
void floyd()
{
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test, u, v, inc, exp, caseno = 1;

    scanf("%d", &test);

    while(test--){
    	scanf("%d %d %d", &n, &r, &p);
    	init();
    	for(int i = 0; i < r; i++){
    		scanf("%d %d %d %d", &u, &v, &inc, &exp);
    		cost[u][v] = exp * p - inc;
    	}

    	floyd();
    	bool isFound = false;

    	for(int i = 0; i < n; i++){
    		if(cost[i][i] < 0){
    			isFound = true;
    			break;
    		}
    	}

    	printf("Case %d: ", caseno++);
    	(isFound) ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}