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

vector<int> graph[MAX];
int ans[MAX];

void solve()
{
    int n;
    string str;

    cin>>n>>str;

    int k = n, x = 0, tx = (1<<(k - 1));
    REP(i, str.size()) {
        if(x >= (1<<(k - 1))) {
            x -= (1<<(k - 1));
            k--;
            tx = (1<<(k - 1));
        }
        if(i % 2 == 0) {
            graph[i].pb(i + tx);
            graph[i + tx].pb(i);
        }
        else {
            graph[i].pb((i - 1) + tx);
            graph[(i - 1) + tx].pb(i);
            tx--;
        }
        x++;
        if(graph[i].size() == 1)
            ans[i] = (str[i] == '?') ? 2 : 1;
        else {
            if(str[i] == '?')
                ans[i] = ans[graph[i][0]] + ans[graph[i][1]];
            else
                ans[i] = ans[graph[i][str[i]-'0']];
        }
    }

    int q;
    cin>>q;

    while(q--) {
        int pos;
        char ch;

        cin>>pos>>ch;
        pos--;

        int curr = pos;
        str[pos] = ch;
        while(true) {
            if(curr == ((1 << n) - 1))
                break;
            if(graph[curr].size() == 1) {
                ans[curr] = (str[curr] == '?') ? 2 : 1;
                curr = graph[curr][0];
            }
            else {
                if(str[curr] == '?')
                    ans[curr] = ans[graph[curr][0]] + ans[graph[curr][1]];
                else
                    ans[curr] = ans[graph[curr][str[curr]-'0']];
                curr = graph[curr][2];
            }
        }

        cout<<ans[(1<<n)-2]<<endl;
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

