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

void solve()
{
    int n;
    string str;

    cin>>n>>str;

    vi pref(n + 1, 0), suff(n + 1, 0);

    REP(i, n) {
        if(str[i] == 'L') {
            if(i - 1 >= 0 && str[i-1] == 'R' && i - 2 >= 0 && str[i-2] == 'L') {
                pref[i+1] = pref[i-1] + 2;
            }
            else if(i - 1 >= 0 && str[i-1] == 'R')
                pref[i+1] = 2;
            else
                pref[i+1] = 1;
        }
        else {
            pref[i+1] = 0;
        }
    }

    ROF(i, n - 1, 0) {
        if(str[i] == 'R') {
            if(i + 1 < n && str[i+1] == 'L' && i + 2 < n && str[i+2] == 'R')
                suff[i] = suff[i+2] + 2;
            else if(i + 1 < n && str[i+1] == 'L')
                suff[i] = 2;
            else
                suff[i] = 1;
        }
        else {
            suff[i] = 0;
        }
    }

    FOR(i, 0, n) {
        cout<<pref[i] + suff[i] + 1<<" ";
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

