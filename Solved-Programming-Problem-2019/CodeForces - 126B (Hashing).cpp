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
#define MAX 1000005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll hashes[MAX], p[MAX];
string str;

ll powMod(ll a, ll b)
{
    ll res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin>>str;
    int n = str.size();
    
    p[0] = 1;
    for(int i = 1; i < n; i++)
        p[i] = (p[i-1] * 31) % MOD;

    hashes[0] = 0;
    for(int i = 0; i < n; i++){
        hashes[i+1] = (hashes[i] + ((str[i]-'a'+1) * p[i]) % MOD) % MOD;
    }
    vector<int> v;
    for(int i = 0; i < n - 2; i++){
        ll h1 = (hashes[i+1]);
        ll h2 = ((hashes[n] + MOD - hashes[n-i-1]) % MOD * powMod(p[n-i-1], MOD - 2)) % MOD;
        //cout<<h1<<" "<<h2<<endl;
        if(h1 == h2)
            v.pb(i + 1);
    }
    int low = 0, high = v.size() - 1, mid, ans = -1;
    while(low <= high){
        mid = (low + high + 1) >> 1;
        ll t = hashes[v[mid]];
        bool flag = false;
        for(int i = 2; i <= n - v[mid]; i++){
            ll h = (hashes[i+v[mid]-1] + MOD - hashes[i-1]) % MOD;
            h = (h * powMod(p[i-1], MOD - 2)) % MOD;
            //cout<<h<<endl;
            if(h == t){
                flag = true;
                break;
            }
        }
        if(flag){
            ans = v[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        
    }

    (ans == -1) ? cout<<"Just a legend"<<endl : cout<<str.substr(0, ans)<<endl;

    return 0;
}
