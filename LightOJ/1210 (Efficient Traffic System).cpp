// BISMILLAHIR RAHMANIR RAHIM
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
#define MAX 20005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;

vi G[MAX], R[MAX];
int finish[MAX], com[MAX], visited[MAX], indegree[MAX], outdegree[MAX], top, scc;

void dfs1(int u)
{
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(!visited[v]){
            visited[v] = 1;
            dfs1(v);
        }
    }
    finish[top++] = u;
}

void dfs2(int u)
{
    for(int i = 0; i < R[u].size(); i++){
        int v = R[u][i];
        if(!visited[v]){
            visited[v] = 1;
            dfs2(v);
        }
    }
    com[u] = scc;
}

int main()
{
    //read; write;
    int test, caseno = 1, u, v, n, m;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < MAX; i++){
            G[i].clear();
            R[i].clear();
        }
        for(int i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            G[u].pb(v);
            R[v].pb(u);
        }

        top = 0;
        mem(visited, 0);

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                visited[i] = 1;
                dfs1(i);
            }
        }

        scc = 0;        //number of strongly connected component
        mem(visited, 0);

        for(int i = top - 1; i >= 0; i--){
            int x = finish[i];
            //cout<<x<<endl;
            if(!visited[x]){
                visited[x] = 1;
                dfs2(x);
                scc++;
            }
        }

        if(scc == 1){
            printf("Case %d: 0\n", caseno++);
            continue;
        }

        mem(indegree, 0);
        mem(outdegree, 0);

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < G[i].size(); j++){
                int x = G[i][j];
                //cout<<com[i]<<" "<<com[x]<<endl;
                if(com[i] != com[x]){
                    //cout<<com[i]<<" "<<com[x]<<endl;
                    outdegree[com[i]]++;
                    indegree[com[x]]++;
                }
            }
        }

        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < scc; i++){
            if(!outdegree[i])   cnt2++;
            if(!indegree[i]) cnt1++;
        }

        printf("Case %d: %d\n", caseno++, max(cnt1, cnt2));
    }

    return 0;
}
