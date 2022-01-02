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
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

string getAns(string str1, string str2, char ch)
{
    int n = (int) str1.size() / 2;
    vector<int> v1, v2;
    string ans = "";

    v1.pb(-1), v2.pb(-1);

    REP(i, 2 * n) {
        if(str1[i] == ch) {
            v1.pb(i);
        }
        if(str2[i] == ch) {
            v2.pb(i);
        }
    }

    REP(i, n) {
        FOR(j, v1[i] + 1, v1[i+1] - 1) {
            ans += str1[j];
        }
        FOR(j, v2[i] + 1, v2[i+1] - 1)
            ans += str2[j];
        ans += ch;
    }

    FOR(j, v1[n] + 1, 2 * n - 1)     ans += str1[j];
    FOR(j, v2[n] + 1, 2 * n - 1)     ans += str2[j];

    return ans;
}

void solve()
{
    int n;

    cin>>n;

    vector<string> vs[2];

    string str;
    REP(i, 3) {
        cin>>str;
        vector<int> cnt(2, 0);
        REP(i, 2 * n) {
            cnt[0] += (str[i] == '0');
            cnt[1] += (str[i] == '1');
        }
        if(cnt[0] >= n)
            vs[0].pb(str);
        else
            vs[1].pb(str);
    }

    string ans;
    if(vs[0].size() >= 2) {
        ans = getAns(vs[0][0], vs[0][1], '0');
    }
    else
        ans = getAns(vs[1][0], vs[1][1], '1');

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

