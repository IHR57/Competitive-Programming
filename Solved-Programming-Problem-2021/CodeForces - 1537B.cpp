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
#define all(v) v.begin(),v.end()
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
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

void solve()
{
    ll n, m, x, y;

    cin>>n>>m>>x>>y;

    vector<pair<ll, ll> > vp;
    vp.pb(mk(1, 1));
    vp.pb(mk(1, m));
    vp.pb(mk(n, 1));
    vp.pb(mk(n, m));

    ll maxD = -1, p1, q1, p2, q2;
    REP(i, vp.size()) {
        REP(j, vp.size()) {
            ll temp = abs(x - vp[i].ff) + abs(y - vp[i].ss) + abs(vp[i].ff - vp[j].ff) + abs(vp[i].ss - vp[j].ss) + abs(x - vp[j].ff) + abs(y - vp[j].ss);
            if(temp > maxD) {
                maxD = temp;
                p1 = vp[i].ff, q1 = vp[i].ss;
                p2 = vp[j].ff, q2 = vp[j].ss;
            }
        }
    }

    cout<<p1<<" "<<q1<<" "<<p2<<" "<<q2<<endl;

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

