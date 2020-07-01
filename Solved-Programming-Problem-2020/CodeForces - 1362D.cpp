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
#define MAX 500005
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
int arr[MAX];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n, m;
    map<ii, int> mp;
    vector<ii> vp;
 
    cin>>n>>m;
 
    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
        vp.pb(mk(u, v));
    }
 
    vector<ii> vres;
 
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        vres.pb(mk(arr[i], i));
    }
 
    int ans = 1200;
 
    for(int i = 1; i <= n; i++) {
        if(arr[i] > ans) {
            cout<<-1<<endl;
            return 0;
        }
    }
 
    for(int i = 0; i < vp.size(); i++) {
        mp[mk(vp[i].ff, arr[vp[i].ss])] = 1;
        mp[mk(vp[i].ss, arr[vp[i].ff])] = 1;
    }
 
    for(int i = 1; i <= n; i++){
        for(int j = arr[i] - 1; j >= 1; j--) {
            if(!mp.count(mk(i, j))) {
                cout<<-1<<endl;
                return 0;
            }
        }
        if(mp.count(mk(i, arr[i]))){
            cout<<-1<<endl;
            return 0;
        }
    }
 
    sort(vres.begin(), vres.end());
 
    for(int i = 0; i < vres.size(); i++) {
        cout<<vres[i].ss<<" ";
    }
    cout<<endl;
 
    return 0;
}