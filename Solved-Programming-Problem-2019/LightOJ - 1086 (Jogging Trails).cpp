//Problem ID: LightOJ - 1086 (Jogging Trails)
//Programmer: IQBAL HOSSAIN     Description: DP + Graph + Chinese-Postman
//Date: 03/04/19
#include <bits/stdc++.h>
#define MAX 17
using namespace std;

int n, dist[MAX][MAX], degree[MAX];
const int inf = 1<<28;
int dp[1<<17];

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

void init()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = inf;
        }
    }
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;
}

int solve(int mask)
{
    if(mask == 0)
        return 0;
    if(dp[mask] != -1)
        return dp[mask];

    int idx;
    for(int i = 0; i < n; i++){
        if(check(mask, i)){
            idx = i;
            break;
        }
    }

    int ret = inf;
    for(int i = idx + 1; i < n; i++){
        if(check(mask, i)){
            ret = min(ret, dist[idx][i] + solve(mask ^ (1 << idx) ^ (1 << i)));
        }
    }

    return dp[mask] = ret;
}

int main()
{
    int m, u, v, c, test, caseno =  1, cost;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        init();
        cost = 0;
        memset(degree, 0, sizeof(degree));
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &c);
            cost += c;
            u--, v--;
            degree[u]++, degree[v]++;
            if(c < dist[u][v]){
                dist[u][v] = dist[v][u] = c;
            }
        }
        for(int k = 0; k < n; k++){         //Floyd-Warshall
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        /* If there is no Euler cycle then some edges will be visited more than once, according to Chinese postman problem
        we have to combine the odd degree in such a way that the cost will be less, for this we have to calculate shortest path
        between every node and then we have to run Bit-mask-dp to compute the best combination of odd degree*/

        int mask = 0;
        for(int i = 0; i < n; i++){
            if(degree[i] % 2 == 1){         //odd degree
                mask = mask | (1 << i);
            }
        }

        memset(dp, -1, sizeof(dp));
        int result = solve(mask);

        printf("Case %d: %d\n", caseno++, cost + result);
    }

    return 0;
}
