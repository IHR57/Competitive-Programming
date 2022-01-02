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

ll sTable[MAX][20];

bool isPossible(int l, int r)
{
    ll x = r - l + 1, k = 0;
    ll res = 1;
    while(res * 2 < x) {
        res *= 2;
        k++;
    }

    ll temp = __gcd(sTable[l][k], sTable[r - res + 1][k]);

    return temp > 1;
}

void solve()
{
    int n;
    cin>>n;

    vector<ll> arr(n), d(n);

    REP(i, n)   cin>>arr[i];
    REP(i, n - 1) {
        d[i] = abs(arr[i] - arr[i+1]);
    }
    n--;

    REP(i, n)   sTable[i][0] = d[i];

    FOR(j, 1, 19)
        REP(i, n)
            sTable[i][j] = __gcd(sTable[i][j-1], sTable[min(n - 1, i + (1<<(j - 1)))][j-1]);

    int ans = 0;

    REP(i, n) {
        if(d[i] == 1)
            continue;
        int low = 0, high = n - i - 1, mid, res = -1;
        while(low <= high) {
            mid = (low + high + 1) >> 1;
            if(isPossible(i, i + mid)) {
                res = mid;
                low = mid + 1;
            }
            else    high = mid - 1;
        }
        ans = max(ans, res + 1);
    }

    cout<<ans + 1<<endl;
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

