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

bool compare(pair<int, int> A, pair<int, int> B) {
    if(A.first == B.first)
        return A.second < B.second;
    return A.first > B.first;
}
void solve()
{
    int n, x, y, z;

    cin>>n>>x>>y>>z;
    vector<pair<int, int> > math, english;
    vi msc(n + 1), esc(n + 1);

    int val;
    REP(i, n) {
        cin>>val;
        math.pb(mk(val, i));
        msc[i] = val;
    }

    REP(i, n) {
        cin>>val;
        english.pb(mk(val, i));
        esc[i] = val;
    }

    sort(math.begin(), math.end(), compare);
    sort(english.begin(), english.end(), compare);

    vector<int> ans;
    vector<int> mark(n + 1, 0);
    REP(i, x) {
        mark[math[i].ss] = 1;
        ans.pb(math[i].ss);
    }
    int cnt = 0;
    REP(i, n) {
        if(cnt == y)
            break;
        if(!mark[english[i].ss]) {
            mark[english[i].ss] = 1;
            ans.pb(english[i].ss);
            cnt++;
        }
    }

    vector<pair<int, int> > vp;
    cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!mark[i]) {
            mark[i] = 1;
            vp.pb(mk(msc[i] + esc[i], i));
        }
    }
    sort(vp.begin(), vp.end(), compare);

    for(int i = 0; i < z; i++) {
        ans.pb(vp[i].ss);
    }

    SORT(ans);
    REP(i, x + y + z) {
        cout<<ans[i] + 1<<" ";
    }
    cout<<endl;

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

