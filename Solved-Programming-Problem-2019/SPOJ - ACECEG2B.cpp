#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 1e17
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<string> vs(MAX, "");

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, q, u, v;
    string str;

    map<ii, int> mp;

    cin>>n;

    int idx = 1;
    for(int i = 0; i < n; i++){
        cin>>u>>v>>str;
        if(mp[mk(u, v)] == 0)
            mp[mk(u,v)] = idx++;
        vs[mp[mk(u, v)]] = str;
    }

    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>u>>v;
        cout<<vs[mp[mk(u, v)]]<<endl;
    }
    
    return 0;
}
