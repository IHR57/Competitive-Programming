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

int arr[MAX];

void solve()
{
    int n, l;

    cin>>n>>l;

    REP(i, n)   cin>>arr[i];

    vector<pair<double, double> > dist(n);

    int v = 1, prev = 0;
    REP(i, n) {
        if(i > 0)
            dist[i].ff += dist[i-1].ff;
        dist[i].ff += (double) (arr[i] - prev) / v;
        v += 1;
        prev = arr[i];
    }

    prev = l, v = 1;
    ROF(i, n - 1, 0) {
        if(i != n - 1)
            dist[i].ss += dist[i+1].ss;
        dist[i].ss += (double) (prev - arr[i]) / v;
        v++;
        prev = arr[i];
    }

    int idx = -1;
    REP(i, n) {
        if(dist[i].ff - dist[i].ss > 0)
            break;
        idx = i;
    }

    double low = (idx != -1) ? arr[idx] : 0;
    double high = (idx == n - 1) ? l : arr[idx+1];
    double tlow = low, thigh = high, td1 = (idx != -1) ? dist[idx].ff : 0, td2 = (idx == n - 1) ? 0 : dist[idx+1].ss;

    int v1 = idx + 2, v2 = (n - idx);
    double ans;

    for(int i = 0; i <= 200 && low + EPS < high; i++) {
        double mid = 0.5 * (low + high);
        double req1 = td1 + (mid - tlow) / v1;
        double req2 = td2 + (thigh - mid) / v2;
        if(abs(req1 - req2) <= EPS) {
            ans = req1;
            break;
        }
        else if((req1- req2) < EPS)
            low = mid;
        else {
            high = mid;
        }
    }

    cout<<setiosflags(ios::fixed)<<setprecision(10);
    cout<<ans<<endl;

    return;
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

