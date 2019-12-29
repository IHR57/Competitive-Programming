/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
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
#define MAX 5005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dp[MAX][MAX];

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

int ans[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    string str;

    cin>>str;
    int n = str.length();

    for(int i = 0; i < n; i++)
        dp[i][i] = 1;

    PolyHash :: base = 29;
    int maxPow = n;

    PolyHash hash_a(str);
    reverse(str.begin(), str.end());
    PolyHash hash_b(str);

    for(int k = 2; k <= n; k++){
        for(int i = 0; i <= n - k; i++){
            if(hash_a(i, k / 2, maxPow) == hash_b(n - (i + k), k / 2, maxPow)){
                dp[i][i+k-1] = dp[i][i + (k/2) - 1] + 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int k = 0; k <= n; k++){
            ans[dp[i][k]]++;
        }
    }

    for(int i = n; i >= 1; i--){
        ans[i] = ans[i] + ans[i+1];
    }

    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
