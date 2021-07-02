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

bool vis[100005];

void solve()
{
    int n;

    cin>>n;

    vi v;

    mem(vis, 0);

    REP(i, n) {
        int x;
        cin>>x;
        v.pb(x);
        if(x > 0)
            vis[x] = 1;
    }

    while(true) {
        vi temp;
        bool found = false;
        REP(i, v.size()) {
            FOR(j, i + 1, v.size() - 1) {
                int k = abs(v[i] - v[j]);
                if(!vis[k]) {
                    temp.pb(k);
                    vis[k] = 1;
                    found = true;
                }
            }
        }

        REP(i, temp.size()) v.pb(temp[i]);

        if(!found || v.size() > 300)
            break;
    }

    int sz = v.size();
    if(sz <= 300) {
        cout<<"YES"<<endl;
        cout<<sz<<endl;
        REP(i, v.size())    cout<<v[i]<<" ";
        cout<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }

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

