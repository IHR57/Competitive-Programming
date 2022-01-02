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

set<int> st[MAX];
int mark[MAX], cnt;

void setVal(int u)
{
    if(st[u].empty()) {
        if(!mark[u]) {
            mark[u] = 1;
            cnt++;
        }
        return;
    }
    if(*st[u].rbegin() < u) {
        if(!mark[u]) {
            mark[u] = 1;
            cnt++;
        }
    }
    else {
        if(mark[u]) {
            mark[u] = 0;
            cnt--;
        }
    }
}

void solve()
{
    int n, m;

    cin>>n>>m;

    cnt = 0;

    REP(i, m) {
        int u, v;
        cin>>u>>v;
        st[u].insert(v);
        st[v].insert(u);
        setVal(u);
        setVal(v);
    }

    int q;

    cin>>q;

    FOR(i, 1, n) {
        if(st[i].empty()) {
            mark[i] = 1;
            cnt++;
        }
    }

    REP(i, q) {
        int type, u, v;
        cin>>type;
        if(type == 3) {
            cout<<cnt<<endl;
        }
        else {
            cin>>u>>v;
            if(type == 1) {
                st[u].insert(v);
                st[v].insert(u);
                setVal(u);
                setVal(v);
            }
            else {
                st[u].erase(v);
                st[v].erase(u);
                setVal(u);
                setVal(v);
            }
        }
    }

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

