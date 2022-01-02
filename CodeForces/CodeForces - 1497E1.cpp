//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mem(a, b)       memset(a, b, sizeof(a))
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
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
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

#define MAX_PRIME 4000

int arr[MAX], primes[MAX_PRIME], mark[MAX_PRIME], counter = 0;
bool vis[10000005];

void genSieve() {

    int limit = sqrt(MAX_PRIME + 5);
    mark[1] = 1;
    for(int i = 4; i < MAX_PRIME; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;
    for(int i = 3; i < MAX_PRIME; i += 2) {
        if(!mark[i]) {
            primes[counter++] = i;
            if(i <= limit) {
                for(int j = i * i; j < MAX_PRIME; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

int factorize(int n) {
    int idx = 0, pf = primes[idx];
    int ans = 1;
    while(pf * pf <= n) {
        if(n % pf == 0) {
            int cnt = 0;
            while(n % pf == 0) {
                n /= pf;
                cnt++;
            }
            if(cnt & 1) {
                ans *= pf;
            }
        }
        pf = primes[++idx];
    }

    ans *= n;

    return ans;
}

void solve()
{
    int n, k, ans = 0;

    cin>>n>>k;

    map<int, int> mp;

    REP(i, n) {
        cin>>arr[i];
        int k = factorize(arr[i]);
        if(mp[k]) {
            mp.clear();
            ans++;
        }
        mp[k] = 1;
    }

    cout<<ans + 1<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test = 1;
    genSieve();

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}