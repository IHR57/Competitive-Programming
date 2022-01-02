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
typedef priority_queue<ll,vector<ll>,greater<ll> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

string grid[11];
int vis[11][20];

void solve()
{
    int n, m, k;

    cin>>n>>m>>k;

    mem(vis, 0);

    REP(i, n) {
        cin>>grid[i];
    }

    ROF(i, n - 1, 0) {
        ROF(j, m - 1, 0) {
            if(grid[i][j] == '*') {
                int cnt = 0;
                for(int x = 1; x <= n; x++) {
                    if((i - x) < 0 || (j - x) < 0 || grid[i-x][j-x] != '*') {
                        break;
                    }
                    if((i - x) < 0 || (j + x) >= m || grid[i-x][j+x] != '*') {
                        break;
                    }
                    cnt++;
                }
                if(cnt >= k) {
                    for(int x = 0; x <= cnt; x++) {
                        vis[i-x][j-x] = vis[i-x][j+x] = 1;
                    }
                }
            }
        }
    }

    REP(i, n) {
        REP(j, m) {
            if((grid[i][j] == '*' && !vis[i][j]) || (grid[i][j] == '.' && vis[i][j])) {
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;


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

