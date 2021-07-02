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
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define all(v)          v.begin(),v.end()
#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.rbegin(),v.rend())
#define REV(v)          reverse(v.begin(),v.end())
#define INF 2147483647
#define MOD 998244353
#define MAX 300005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef pair<ll, ll> LL;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int grid[805][805];
int dp[805][805];

void solve()
{
    int n,k;

    cin>>n>>k;

    vi v;

    REP(i, n) {
        REP(j, n) {
            cin>>grid[i][j];
            v.pb(grid[i][j]);
        }
    }

    SORT(v);

    int low = 0, high = (n * n) - 1, mid, ans = -1;

    while(low <= high) {
        mid = (low + high) >> 1;
        bool flag = false;

        mem(dp, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (grid[i-1][j-1] <= v[mid]);
            }
        }

        for(int i = 0; i <= n - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                int cnt = dp[i+k][j+k] - dp[i][j+k] - dp[i+k][j] + dp[i][j];
                int lim = ((k % 2 == 1) ? ((k * k) / 2 + 1) : (k * k) / 2);
                if(cnt >= lim) {
                    ans = mid;
                    flag = true;
                    break;
                }
            }
        }


        if(flag) {
            ans = v[mid];
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    //cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

