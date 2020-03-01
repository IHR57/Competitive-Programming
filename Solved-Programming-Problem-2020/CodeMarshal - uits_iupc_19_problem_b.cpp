//Date: 21/02/2020
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 1005
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int mark[MAX], dfsCnt, color[2];
vector<int> vp;
vector<int> graph[MAX];

void dfs(int u, int c, int sc)
{
    if(!sc)
        vp.pb(u);
    mark[u]++;
    color[c]++;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(mark[v] == dfsCnt)
            continue;
        dfs(v, !c, sc);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, n, u, v, m, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d",  &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        int ans = 0;
        dfsCnt = 0;
        for(int i = 1; i <= n; i++){
            if(!mark[i]){
                vp.clear();
                dfsCnt = 1;
                color[0] = color[1] = 0;
                dfs(i, 0, 0);
                int Mx = max(color[0], color[1]);

                for(int j = 0; j < vp.size(); j++){
                    if(vp[j] != i){
                        color[0] = color[1] = 0;
                        dfsCnt++;
                        dfs(vp[j], 0, 1);
                        Mx = max(Mx, max(color[0], color[1]));
                    }
                }

                ans += Mx;
            }
        }

        printf("Case %d: %d\n", caseno++, ans);
        for(int i = 1; i <= n; i++){
            graph[i].clear();
            mark[i] = 0;
        }

    }

    return 0;
}