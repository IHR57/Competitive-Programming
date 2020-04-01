//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> graph[MAX];
vector<ii> vp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;
    int u, v;

    map<ii, int> mp;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
        vp.pb(mk(u, v));
    }

    bool found = false;
    for(int i = 1; i <= n; i++){
        if(graph[i].size() >= 3){
            found = true;
            int cnt = 0;
            for(int j = 0; j < 3; j++){
                v = graph[i][j];
                mp[mk(i, v)] = cnt;
                mp[mk(v, i)] = cnt;
                cnt++;
            }
            break;
        }
    }

    int cnt = 0;
    if(found)
        cnt = 3;
    for(int i = 0; i < vp.size(); i++){
        if(!mp.count(mk(vp[i].ff, vp[i].ss))){
            mp[mk(vp[i].ff, vp[i].ss)] = cnt++;
        }
    }

    for(int i = 0; i < vp.size(); i++){
        cout<<mp[mk(vp[i].ff, vp[i].ss)]<<endl;
    }

    return 0;
}
