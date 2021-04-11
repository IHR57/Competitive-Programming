//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 998244353
#define MAX 200005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos) { return mask = mask | (1<<pos); }
bool checkBit(int mask, int pos) { return (bool)(mask & (1<<pos)); }

int n;
ll arr[MAX];
ll dp[MAX][3][2];

ll solve(int pos, int type, int start)
{
    if(pos >= n)
        return 0;

    if(dp[pos][type][start] != -1)
        return dp[pos][type][start];

    ll ret = 0;
    if(type == 0) {
        ret = ((pos % 2 == 0) ? arr[pos] : 0)  + solve(pos + 1, type, start);
        if(pos + 1 < n)
            ret = max(ret, ((pos % 2 == 0) ? 0 : arr[pos]) + solve(pos + 1, type + 1, (pos % 2)));
    }
    else if(type == 1) {
        ll x = (pos % 2 == 0) ? 0 : arr[pos];
        if(pos % 2 != start && pos + 1 >= n - 1) {
            ret = max(ret, x + solve(pos + 1, type + 1, start));
        }
        else {
            ret = x + solve(pos + 1, type, start);
            if(pos % 2 != start)
                ret = max(ret, x + solve(pos + 1, type + 1, start));
        }
    }
    else if(type == 2) {
        ret = ((pos % 2 == 0) ? arr[pos] : 0) + solve(pos + 1, type, start);
    }

    return dp[pos][type][start] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test;

    scanf("%d", &test);

    while(test--) {
        scanf("%d",  &n);
        for(int i = 0; i <= n; i++) 
            for(int j = 0; j < 3; j++) 
                for(int k = 0; k < 2; k++)
                    dp[i][j][k] = -1;

        for(int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
        }

        ll res = solve(0, 0, 0);

        printf("%lld\n", res);
    }

    return 0;
}


