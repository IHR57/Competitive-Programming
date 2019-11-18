//Date: 07/11/19
//Problem Link: https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=42&id_problem=264
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

//Calculate 1 + a + a^2 + a^3 + ... + a^(k-1)
ll powmod1(ll a, int k)
{
    if(k == 1)
        return 1;
    if(k % 2 == 0){
        return ((1 + a) * powmod1((a * a) % MOD, k >> 1)) % MOD;
    }
    else{
        return (1 + ((1 + a)  * a) % MOD * powmod1((a * a) % MOD, k >> 1)) % MOD;
    }
}

ull powmod2(ull a, int k)
{
    if(k == 1)
        return 1;
    if(k % 2 == 0){
        return (1 + a) * powmod2(a * a, k >> 1);
    }
    else{
        return 1 + a * powmod2(a, k - 1);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    string str;
    int ans = 0;

    cin>>str;
    reverse(str.begin(), str.end());

    PolyHash hash(str);

    int n = str.size();

    for(int i = 1; i <= n; i++){
        pair<ll, ull> hash1 = hash(0, i);
        pair<ll, ull> hash2 = hash(0, n);

        hash1.ff = hash1.ff * powmod1(PolyHash::p1[i], n) % MOD;
        hash2.ff = hash2.ff * powmod1(PolyHash::p1[n], i) % MOD;

        hash1.ss *= powmod2(PolyHash::p2[i], n);
        hash2.ss *= powmod2(PolyHash::p2[n], i);

        if(hash1 == hash2)
            ans++;

    }

    cout<<ans<<endl;

    return 0;
}