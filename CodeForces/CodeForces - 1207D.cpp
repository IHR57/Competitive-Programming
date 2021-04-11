//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 998244353
#define MAX 300005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll fact[MAX];

bool compare(ii A, ii B)
{
    return A.ss < B.ss;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n;

    vector<ii> vp(n);

    for(int i = 0; i < n; i++) {
        cin>>vp[i].first>>vp[i].second;
    }

    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (i * fact[i-1]) % MOD;
    }
    ll ans = fact[n];

    int cnt = 1, prev = 0;
    ll t = 1;

    sort(vp.begin(), vp.end());
    for(int i = 0; i < n; i++) {
        if(vp[i].ff == prev) {
            cnt++;
        }
        else {
            t = (t * fact[cnt]) % MOD;
            cnt = 1;
        }
        prev = vp[i].ff;
    }
    t = (t * fact[cnt]) % MOD;
    ans = ((ans - t) + MOD) % MOD;

    cnt = 1, prev = 0;
    t = 1;

    sort(vp.begin(), vp.end(), compare);

    for(int i = 0; i < n; i++) {
        if(vp[i].ss == prev) {
            cnt++;
        }
        else {
            t = (t * fact[cnt]) % MOD;
            cnt = 1;
        }
        prev = vp[i].ss;
    }

    t = (t * fact[cnt]) % MOD;
    ans = ((ans - t) + MOD) % MOD;

    sort(vp.begin(), vp.end());

    int l = 0, r;
    t = 1;

    for(int i = 1; i < n; i++) {
        if(vp[i-1].ss > vp[i].ss) {
            t = 0;
            break;
        }
    }

    if(t == 0) {
        cout<<ans<<endl;
        return 0;
    }

    while(l < n) {
        r = l + 1;
        while(r < n && vp[l].ff == vp[r].ff)
            r++;
        map<int, int> mp;
        for(int i = l; i < r; i++) {
            mp[vp[i].ss]++;
        }
        for(map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
            //cout<<it->ff<<" "<<it->ss<<endl;
            t = (t * fact[it->ss]) % MOD;
        }
        l = r;
    }
    
    ans = (ans + t) % MOD;

    cout<<ans<<endl;

    return 0;
}


