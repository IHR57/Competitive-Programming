//Date: 13/01/20
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 25
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dist[MAX][MAX], grid[MAX][MAX], vis[MAX][MAX];
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int n, m;

int bfs(int sx, int sy)
{
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    dist[sx][sy] = 0;
    int maxDist = 0;

    queue<ii> q;
    q.push(mk(sx, sy));

    while(!q.empty()){
        ii u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int tx = u.ff + fx[i];
            int ty = u.ss + fy[i];
            if(tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty] && grid[tx][ty] != -1){
                vis[tx][ty] = 1;
                dist[tx][ty] = dist[u.ff][u.ss] + 1;
                maxDist = max(maxDist, dist[tx][ty]);
                q.push(mk(tx, ty));
            }
        }
    }

    return maxDist;

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        for(int j = 0; j < m; j++){
            if(str[j] == '#')
                grid[i][j] = -1;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0)
                ans = max(ans, bfs(i, j));
        }
    }

    cout<<ans<<endl;


    return 0;
}