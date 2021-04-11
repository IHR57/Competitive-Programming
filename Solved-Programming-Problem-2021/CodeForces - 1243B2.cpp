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

void solve()
{
    int n;
    string s, t;

    cin>>n;
    cin>>s>>t;

    vector<int> freq(26, 0);

    REP(i, n)   freq[s[i]-'a']++;
    REP(i, n)   freq[t[i]-'a']++;

    REP(i, 26) {
        if(freq[i] & 1) {
            cout<<"No"<<endl;
            return;
        }
    }

    vector<int> ans;

    REP(i, n) {
        if(s[i] != t[i]) {
            int idx = -1;
            FOR(j, i + 1, n - 1) {
                if(s[j] == s[i]) {
                    idx = j;
                    break;
                }
            }
            if(idx != -1) {
                ans.pb(idx), ans.pb(i);
                swap(t[i], s[idx]);
                continue;
            }
            FOR(j, i + 1, n - 1) {
                if(t[j] == s[i]) {
                    idx = j;
                    break;
                }
            }
            ans.pb(i+1), ans.pb(idx);
            swap(s[i+1], t[idx]);
            ans.pb(i+1), ans.pb(i);
            swap(s[i+1], t[i]);
        }
    }

    cout<<"Yes"<<endl;
    int x = ans.size();

    cout<<(x / 2)<<endl;
    REP(i, ans.size()) {
        cout<<ans[i] + 1<<" ";
    }
    cout<<endl;

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

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}