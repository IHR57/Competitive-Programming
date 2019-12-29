//Problem ID: SPOJ - NHAY (A Needle in the Haystack)
//Programmer: IQBAL HOSSAIN     Description: Hashing
//Date: 30/08/19
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
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string sbstr, str, temp;
    int n;

    while(cin>>n){
        getline(cin, temp);
        getline(cin, sbstr);
        getline(cin, str);
        ll th = 0;
        ll t = 1;
        for(int i = 0; i < n; i++){
            int k = (sbstr[i] == ' ') ? 27 : sbstr[i] - 'a' + 1;
            th = (th + (1LL * k * t) % MOD) % MOD;
            t = (t * 31) % MOD;
        }

        //cout<<th<<endl;
        int sz = str.size();
        vector<ll> hashes(sz+5, 0);
        vector<ll> p(sz + 1, 0);
        p[0] = 1;
        for(int i = 0; i < sz; i++){
            int k = (str[i] == ' ') ? 27 : str[i] - 'a' + 1;
            hashes[i+1] = (hashes[i] + (k * 1LL * p[i]) % MOD) % MOD;
            p[i+1] = (p[i] * 31) % MOD;
            //cout<<hashes[i+1]<<endl;
        }

        vector<int> res;
        for(int i = 1; i <= sz - n + 1; i++){
            ll cur_h = (hashes[i+n-1] + MOD - hashes[i-1]) % MOD;
            cur_h = (cur_h * powMod(p[i-1], MOD - 2)) % MOD;
            //cout<<cur_h<<endl;
            if(cur_h == th){
                res.pb(i-1);
            }
        }

        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<endl;
        }
        cout<<endl;
    }

    return 0;
}
