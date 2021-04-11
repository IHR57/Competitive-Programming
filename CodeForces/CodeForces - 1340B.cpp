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
#define INF 2147483647
#define MOD 998244353
#define MAX 2005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos) { return mask = mask | (1<<pos); }
bool checkBit(int mask, int pos) { return (bool)(mask & (1<<pos)); }

int dp[MAX][MAX], res[MAX];
int n, k;
vector<string> vs, ts;

int check(int x, int y)
{
    int cnt = 0;

    for(int i = 0; i < 7; i++) {
        if(vs[x][i] == '0' && ts[y][i] == '1')
            cnt++;
        if(vs[x][i] == '1' && ts[y][i] == '0')
            return -1;
    }

    return cnt;
}

int solve(int pos, int rem)
{
    if(pos >= n) {
        if(rem == 0)
            return 1;
        return 0;
    }

    if(dp[pos][rem] != -1)
        return dp[pos][rem];

    int ret = 0;
    for(int i = 9; i >= 0; i--) {
        int x = check(pos, i);
        if(x == -1 || x > rem)
            continue;
        int tx = solve(pos + 1, rem - x);
        if(tx == 1) {
            ret = 1;
            res[pos] = i;
            break;
        }
    }

    return dp[pos][rem] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>k;
    string str;

    ts.pb("1110111"), ts.pb("0010010"), ts.pb("1011101"), ts.pb("1011011");
    ts.pb("0111010"), ts.pb("1101011"), ts.pb("1101111"), ts.pb("1010010"), ts.pb("1111111");
    ts.pb("1111011");

    for(int i = 0; i < n; i++) {
        cin>>str;
        vs.pb(str);
    }

    mem(dp, -1);
    int x = solve(0, k);
    if(x == 1) {
        for(int i = 0; i < n; i++) {
            cout<<res[i];
        }
        cout<<endl;
    } else {
        cout<<-1<<endl;
    }

    return 0;
}


