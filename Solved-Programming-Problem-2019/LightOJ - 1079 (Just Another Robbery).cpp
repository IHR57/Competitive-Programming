//Date: 24/11/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 1000000007
#define MAX 10005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(int mask, int pos) { return (bool) (mask & (1<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

int n, cost[105];
double lim, p[105], dp[105][10005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lf %d", &lim, &n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %lf", &cost[i], &p[i]);
            sum += cost[i];
        }

        for(int i = 0; i <= sum; i++)
            dp[n][i] = 1.0;
        dp[n][0] = 0.0;

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= sum; j++){
                dp[i][j] = dp[i+1][j];
                if(j - cost[i] >= 0){
                    dp[i][j] = min(dp[i][j], dp[i+1][j-cost[i]] + (1.0 - dp[i+1][j-cost[i]]) * p[i]);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i <= sum; i++){
            if(dp[0][i] < lim){
                ans = i;
            }
        }

        printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}