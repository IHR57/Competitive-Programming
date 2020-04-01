//Date: 17/03/2020
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
#define MAX 300005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX][3];
int a[MAX], b[MAX], n;

ll solve(int pos, int x)
{
    if(pos >= n)
        return 0;

    if(dp[pos][x] != -1)
        return dp[pos][x];

    ll ret = 2e18;

    for(int i = 0; i <= 2; i++){
        if(pos == 0 || (a[pos] + i != a[pos-1] + x)){
            ret = min(ret, (1LL * i * b[pos]) + solve(pos + 1, i));
        }
    }

    return dp[pos][x] = ret;
}

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%d %d", &a[i], &b[i]);
        }

        for(int i = 0; i <= n; i++){
            dp[i][0] = dp[i][1] = dp[i][2] = -1;
        }

        ll res = solve(0, 0);

        printf("%lld\n", res);
    }
}
