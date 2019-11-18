//Date: 07/11/19
//Problem Link: https://acmp.ru/index.asp?main=task&id_task=829&locale=en
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
#define MAX 1000005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

struct PolyHash
{
    static vector<ll> p1;
    static vector<ull> p2;
    static int base;

    vector<ll> pref1;
    vector<ull> pref2;

    PolyHash(const string& s) : pref1(s.size() + 1, 0), pref2(s.size() + 1, 0){
        int n = s.size();
        p1.clear(), p2.clear();
        p1.pb(1);
        p2.pb(1);

        for(int i = 1; i <= n; i++){
            p1.pb((p1.back() * base) % MOD);
            p2.pb(p2.back() * base);
        }

        for(int i = 0; i < n; i++){
            pref1[i+1] = (pref1[i] + s[i] * p1[i]) % MOD;
            pref2[i+1] = (pref2[i] + s[i] * p2[i]);
        }
    }

    inline pair<ll, ull> operator()(const int pos, const int len, const int maxPow = 0) const{
        ll hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if(hash1 < 0)
            hash1 += MOD;
        if(maxPow != 0){
            hash1 = (hash1 * p1[maxPow-(pos+len-1)]) % MOD;
            hash2 *= p2[maxPow-(pos+len-1)];
        }

        return mk(hash1, hash2);
    }

};

//init static variable
int PolyHash::base((int) 257);  
std::vector<ll> PolyHash::p1;
std::vector<ull> PolyHash::p2;

vector<pair<ll, ull> > hashes;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    string str, pat;

    cin>>str;
    cin>>pat;

    int n = str.size();
    int m = pat.size();
    pat += pat;

    int maxPow = max(str.size(), pat.size());

    PolyHash hash_a(str), hash_b(pat);

    for(int i = 0; i < m; i++){
        hashes.pb(hash_b(i, m, maxPow));
    }

    sort(hashes.begin(), hashes.end());

    int ans = 0;
    for(int i = 0; i <= n - m; i++){
        if(binary_search(hashes.begin(), hashes.end(), hash_a(i, m, maxPow))){
            ans++;
        }
    }

    cout<<ans<<endl;
    

    return 0;
}