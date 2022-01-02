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

int caseno = 1;

void solve()
{
    int x, y;
    string str;

    cin>>x>>y>>str;

    int n = str.size(), idx_i = 0, idx_j = n - 1;
    REP(i, n) {
        if(str[i] != '?')
            break;
        idx_i++;
    }
    ROF(i, n - 1, 0) {
        if(str[i] != '?')
            break;
        idx_j--;
    }

    if(idx_i >= idx_j) {
        cout<<"Case #"<<caseno++<<": "<<0<<endl;
        return;
    }

    string temp = "";
    FOR(i, idx_i, idx_j) {
        if(str[i] != '?')
            temp += str[i];
    }

    int m = temp.size();

    int ans = 0;
    REP(i, m - 1) {
        if(temp[i] == 'C' && temp[i+1] == 'J')
            ans += x;
        else if(temp[i] == 'J' && temp[i+1] == 'C')
            ans += y;
    }

    cout<<"Case #"<<caseno++<<": "<<ans<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int test = 1;

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}