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
#define MAX 200005
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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;

    cin>>n>>m;

    vector<ii> vpa, vpb;

    for(int i = 0; i < n; i++) {
        int u, v;
        cin>>u>>v;
        if(u > v)
            swap(u, v);
        vpa.pb(mk(u, v));
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        if(u > v)
            swap(u, v);
        vpb.pb(mk(u, v));
    }

    map<int, int> freq;

    for(int i = 0; i < n; i++) {
        int p = 0, q = 0;
        for(int j = 0; j < m; j++) {
            if(vpa[i].ff == vpb[j].ff && vpa[i].ss == vpb[j].ss)
                continue;
            if(vpa[i].ff == vpb[j].ff || vpa[i].ff == vpb[j].ss)
                freq[vpa[i].ff]++, p++;
            if(vpa[i].ss == vpb[j].ff || vpa[i].ss == vpb[j].ss)
                freq[vpa[i].ss]++, q++;
        }
        if(p > 0 && q > 0) {
            cout<<-1<<endl;
            return 0;
        }
    }


    freq.clear();

    for(int i = 0; i < m; i++) {
        int p = 0, q = 0;
        for(int j = 0; j < n; j++) {
            if(vpb[i].ff == vpa[j].ff && vpb[i].ss == vpa[j].ss)
                continue;
            if(vpb[i].ff == vpa[j].ff || vpb[i].ff == vpa[j].ss)
                freq[vpb[i].ff]++, p++;
            if(vpb[i].ss == vpa[j].ff || vpb[i].ss == vpa[j].ss)
                freq[vpb[i].ss]++, q++;
        }
        if(p > 0 && q > 0) {
            cout<<-1<<endl;
            return 0;
        }
    }


    if(freq.size() > 1) {
        cout<<0<<endl;
        return 0;
    }

    cout<<freq.begin()->ff<<endl;

    return 0;
}

 
