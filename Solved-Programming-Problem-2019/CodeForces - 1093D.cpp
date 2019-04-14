//Date: 09/04/19
#include <bits/stdc++.h>
#define MAX 300005
#define MOD 998244353
using namespace std;

typedef long long ll;

int color[MAX], p[MAX];
vector<int> graph[MAX];
int black, blue;
bool isOk;

void dfs(int u, int c)
{
    if(c == 1)   black++;
    else    blue++;
    color[u] = c;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(color[v] == -1)
            dfs(v, !c);
        else if(color[v] == c){
            isOk = false;
            break;
        }
    }
}

int main()
{
    int test, n, m, u, v;
    p[0] = 1;
    for(int i = 1; i < MAX; i++){
        p[i] = (2 * p[i-1] ) % MOD;
    }

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        ll ans = 1;
        isOk = true;
        for(int i = 0; i <= n; i++)
            color[i] = -1;
        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                blue = black = 0;
                dfs(i, 0);
                if(isOk == false)
                    break;
                int temp = (p[blue] + p[black]) % MOD;
                ans = (ans * 1LL * temp) % MOD;
            }
        }
        if(isOk){
            printf("%lld\n", ans);
        }
        else{
            printf("0\n");
        }
        for(int i = 0; i <= n; i++)
            graph[i].clear();
    }

    return 0;
}
