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
#define MAX 2005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;

int visited[MAX], Max = 0;
vi graph[MAX];

int dfs(int u)
{
    int d = 0;
    visited[u] = 1;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        //if(!visited[v]){
            d = max(d, dfs(v));
        //}
    }
    return (d + 1);
}

int main()
{
    int n, value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        if(value != -1){
            graph[value].pb(i + 1);
            // graph[i+1].pb(value);
        }
    }

    mem(visited, 0);

    Max = 0;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            Max = max(Max, dfs(i));
        }
    }

    printf("%d\n", Max);

    return 0;
}
