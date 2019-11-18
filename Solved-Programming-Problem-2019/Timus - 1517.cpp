//Date: 29/10/19
//Problem: http://acm.timus.ru/problem.aspx?space=1&num=1517
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
#define MAX 100005
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

    vector<ll> h1;
    vector<ull> h2;

    //constructor from string
    PolyHash(string& s) : h1(s.size() + 1, 0), h2(s.size() + 1, 0)
    {
        const int n = s.size();

        p1.pb(1), p2.pb(1);
        for(int i = 1; i <= n; i++){
            p1.pb((p1.back() * base) % MOD);
            p2.pb((p2.back() * base));
        }

        for(int i = 0; i < n; i++){
            h1[i+1] = (h1[i] + s[i] * p1[i]) % MOD;
            h2[i+1] = (h2[i] + s[i] * p2[i]);
        }
    }

    //Polynomial hash of segment [pos, pos+len];
    inline pair<ll, ull> operator()(const int pos, const int len, const int maxPow = 0) const{
        ll hash1 = h1[pos + len] - h1[pos];
        ull hash2 = h2[pos + len] - h2[pos];
        if(hash1 < 0)
            hash1 += MOD;

        if(maxPow != 0){
            hash1 = hash1 * p1[maxPow-(pos+len-1)] % MOD;
            hash2 *= p2[maxPow-(pos+len-1)];
        }

        return mk(hash1, hash2);
    }

};

//init static variable
int PolyHash::base((int)1e9+7);  
std::vector<ll> PolyHash::p1;
std::vector<ull> PolyHash::p2;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    string str1, str2;
    int n;

    cin>>n;
    cin>>str1;
    cin>>str2;

    PolyHash::base = 129;
    PolyHash hash_a(str1), hash_b(str2);
    int maxPow = max(str1.size(), str2.size());

    int low = 0, high = n, idx = -1, ans;

    while(low <= high){
        int mid = (low + high + 1) >> 1;
        vector<pair<ll, ull> >hashes;
        int p = - 1;
        for(int i = 0; i <= n - mid; i++){
            hashes.pb(hash_a(i, mid, maxPow));
        }

        sort(hashes.begin(), hashes.end());

        for(int i = 0; i <= n - mid; i++){
            if(binary_search(hashes.begin(), hashes.end(), hash_b(i, mid, maxPow))){
                p = i;
                break;
            }
        }
        if(p >= 0){
            ans = mid;
            idx = p;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout<<str2.substr(idx, ans)<<endl;

    return 0;
}
