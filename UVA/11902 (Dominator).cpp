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
#define pb push_back
#define all(v) (v.begin(), v.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI acos(-1)
#define pi 2*acos(0)
#define MOD 1000000007
#define INF 2147483647
#define mp make_pair
#define sin(a) sin(a*pi/180)
#define cos(a) cos(a*pi/180)
#define tan(a) tan(a*pi/180)
#define sini(a) asin(a) / (pi/180)
#define cosi(a) acos(a) / (pi/180)
#define tani(a) atan(a) / (pi/180)
#define dis(x1, y1, x2, y2) ((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2))
#define debug (printf("PINK FLOYD:)\n"))
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 105
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;

int visited[MAX], vis[MAX], x;
vi graph[MAX];

void dfs(int u)
{
    visited[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v] && v != x){
            dfs(v);
        }
    }
}

void dfs2(int u)
{
    vis[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!vis[v]){
            dfs2(v);
        }
    }
}
int main()
{
    //read; write;
    int test, n, mat[MAX][MAX], value, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &value);
                if(value == 1){
                    graph[i].pb(j);     //directed graph
                }
            }
        }

        mem(mat, 0);
        mem(vis, 0);

        dfs2(0);
        for(int i = 0; i < n; i++){
            if(vis[i])
                mat[0][i] = 1;
        }

        for(int i = 1; i < n; i++){
            x = i;
            mem(visited, 0);
            dfs(0);
            for(int j = 0; j < n; j++){
                if(!visited[j] && vis[j]){
                    mat[i][j] = 1;
                }
            }
        }
        printf("Case %d:\n", caseno++);
        printf("+");
        for(int i = 0; i < 2 * n - 1; i++){
            printf("-");
        }
        printf("+\n");
        for(int i = 0; i < n; i++){
            printf("|");
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    printf("Y|");
                }
                else
                    printf("N|");
            }
            printf("\n");
            printf("+");
            for(int i = 0; i < 2 * n - 1; i++){
                printf("-");
            }
            printf("+\n");
        }
        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}
