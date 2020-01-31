//Date: 31/12/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> v[MAX];
int res[MAX], cnt[MAX], req[MAX], vis[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n;

    for(int i = 0; i < n - 2; i++){
        int a, b, c;
        cin>>a>>b>>c;
        v[a].pb(b);
        v[a].pb(c);
        v[b].pb(a);
        v[b].pb(c);
        v[c].pb(a);
        v[c].pb(b);
        cnt[a]++, cnt[b]++, cnt[c]++;
        req[i] = 3;
    }

    req[0] = req[n-1] = 1;
    req[1] = req[n-2] = 2;

    int src = -1;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 1){
            src = i;
            break;
        }
    }

    int idx = 0;
    res[idx] = src;
    vis[src] = 1;
    bool foundX = false;

    while(true){
        int x, y;
        x = -1, y = -1;
        for(int i = 0; i < v[src].size(); i++){
            if(vis[v[src][i]])
                continue;
            if(!foundX && cnt[v[src][i]] == req[idx+1]){
                x = v[src][i];
            }
            if(cnt[v[src][i]] == req[idx+2]){
                y = v[src][i];
            }
        }
        //cout<<x<<" "<<y<<endl;
        if(x != -1){
            res[idx+1] = x;
            res[idx+2] = y;
            vis[x] = vis[y] = 1;
            foundX = true;
        }
        else{
            res[idx+2] = y;
            vis[y] = 1;
        }
        if(idx + 2 >= n - 1)
            break;
        idx++;
        src = res[idx];

    }

    for(int i = 0; i < n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}