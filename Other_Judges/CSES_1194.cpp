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
#define MAX 1000005
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

int fx[] = { 1, -1, 0, 0 };
int fy[] = { 0, 0, 1, -1 };
string dirs = "DURL";

char grid[1005][1005];
int dist[1005][1005];
ii parent[1005][1005];
int n, m;
int dest_r = -1, dest_c = -1;
string ans;

void buildPath(int x, int y) {
    ii par = parent[x][y];
    if(par.ff == -1 && par.ss == -1) {
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(par.ff + fx[i] == x && par.ss + fy[i] == y) {
            ans.pb(dirs[i]);
            break;
        }
    }

    buildPath(par.ff, par.ss);
}

void bfs(vector<pair<int, int>>& vp, bool isHero) {

    queue<pair<int, int>> q;
    for(int i = 0; i < vp.size(); i++) {
        q.push({vp[i].ff, vp[i].ss});
        dist[vp[i].ff][vp[i].ss] = 0;
    }

    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = u.first + fx[i];
            int ty = u.second + fy[i];
            if(tx >= 0 && tx < n && ty >= 0 && ty < m && dist[tx][ty] > dist[u.first][u.second] + 1 && grid[tx][ty] != '#') {
                dist[tx][ty] = dist[u.first][u.second] + 1;
                q.push({tx, ty});
                parent[tx][ty] = {u.first, u.second};
            }
            if(isHero && (u.first == 0 || u.second == 0 || u.first == n - 1 || u.second == m - 1)) {
                dest_r = u.first, dest_c = u.second;
                return;
            }
        }
    }
}

void solve() {
    vii monsters, heroes;

    cin>>n>>m;

    REP(i, n) {
        REP(j, m) {
            dist[i][j] = INF;
            cin>>grid[i][j];
            if(grid[i][j] == 'M')
                monsters.pb({i, j});
            if(grid[i][j] == 'A')
                heroes.pb({i, j});
        }
    }

    //REP(i, n)   REP(j, m)   cout<<grid[i][j];

    bfs(monsters, false);
    parent[heroes[0].ff][heroes[0].ss] = {-1, -1};
    bfs(heroes, true);

    if(dest_r != -1 && dest_c != -1) {
        cout<<"YES"<<endl;
        cout<<dist[dest_r][dest_c]<<endl;
        buildPath(dest_r, dest_c);
        REV(ans);
        cout<<ans<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
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

