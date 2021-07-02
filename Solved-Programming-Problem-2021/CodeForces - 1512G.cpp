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
#define EPS 1e-8
#define MOD 998244353
#define MAX 100005
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

const int N = 10000000;
int lp[N+1];            // least prime factor
int dp[N+5], ans[N+5];
vector<int> pr;

void fastSieve()            // linear time: http://e-maxx.ru/algo/prime_sieve_linear
{
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb (i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void solve()
{
    int n;

    cin>>n;

    cout<<((ans[n] == 0) ? -1 : ans[n])<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    fastSieve();

    dp[1] = 1, dp[2] = 3; ans[1] = 1, ans[3] = 2;

    FOR(i, 3, N) {
        if(lp[i] == i) {
            dp[i] = lp[i] + 1;
            if(!ans[dp[i]]) {
                ans[dp[i]] = i;
            }
        }
        else {
            int temp = 1, tx = i, tans = 0;
            while(tx % lp[i] == 0) {
                tx /= lp[i];
                tans += temp;
                temp *= lp[i];
            }
            tans += temp;

            if(tx == 1)
                dp[i] = tans;
            else
                dp[i] = dp[temp] * dp[tx];
            if(dp[i] <= N && !ans[dp[i]])
                ans[dp[i]] = i;
        }
    }

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

