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
#define MOD 1000000007
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

int ask(int type, int i, int j, int k)
{
    ++i, ++j;
    int x;
    cout<<"? "<<type<<" "<<i<<" "<<j<<" "<<k<<endl;
    cout.flush();
    cin>>x;

    return x;
}

void solve()
{
    int n;
    cin>>n;

    vi p(n, -1), mark(n + 1, 0);

    for(int i = 1; i < n; i += 2) {
        int idx1 = i - 1, idx2 = i;
        int x = ask(1, idx1, idx2, n - 1);
        if(x == n - 1) {
            x = ask(1, idx2, idx1, n - 1);
            if(x == n) {
                p[idx1] = x;
                p[idx2] = ask(2, idx2, idx1, 1);
                continue;
            }
        }

        int tx = ask(1, idx1, idx2, x - 1);
        if(tx == x - 1) {
            p[idx1] = x;
            p[idx2] = ask(2, idx2, idx1, 1);
        }
        else if(tx == x) {
            p[idx2] = x;
            p[idx1] = ask(2, idx1, idx2, 1);
        }

    }

    if(p[n-1] == -1) {
        REP(i, n - 1)
            mark[p[i]] = 1;
        FOR(i, 1, n) {
            if(!mark[i]) {
                p[n-1] = i;
            }
        }
    }

    cout<<"! ";
    REP(i, n) {
        cout<<p[i]<<" ";
    }
    cout<<endl;

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

