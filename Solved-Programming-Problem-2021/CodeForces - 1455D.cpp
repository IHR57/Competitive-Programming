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

int arr[505];
int dp[505][505][505], n;

int recurs(int pos, int last, int x)
{
    if(pos >= n + 1)
        return 0;
    int &ret = dp[pos][last][x];
    if(ret != -1)
        return ret;

    ret = 1e9;
    if(arr[pos] >= last) {
        ret = min(ret, recurs(pos + 1, arr[pos], x));
        if(arr[pos] > x && x >= last) {
            ret = min(ret, 1 + recurs(pos + 1, x, arr[pos]));
        }
    }
    else {
        if(arr[pos] > x && x >= last) {
            ret = min(ret, 1 + recurs(pos + 1, x, arr[pos]));
        }
    }

    return ret;
}

void solve()
{
    int x;
    cin>>n>>x;

    FOR(i, 1, n)   cin>>arr[i];

    FOR(i, 1, n)
        FOR(j, 0, 500)
            FOR(k, 0, 500)
                dp[i][j][k] = -1;

    int ans = recurs(1, 0, x);

    if(ans > n) {
        cout<<-1<<endl;
        return;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

