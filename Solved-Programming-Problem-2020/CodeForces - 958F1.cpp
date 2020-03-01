//Date: 08/02/2020
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
#define MAX 200005
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

    PolyHash(int arr[], int n) : h1(n + 1, 0), h2(n + 1, 0)
    {
        p1.pb(1), p2.pb(1);
        for(int i = 1; i <= n; i++){
            p1.pb((p1.back() * base) % MOD);
            p2.pb((p2.back() * base));
        }

        for(int i = 0; i < n; i++){
            h1[i+1] = (h1[i] + arr[i] * p1[i]) % MOD;
            h2[i+1] = (h2[i] + arr[i] * p2[i]);
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
    PolyHash::base = 101;
    int a[105], b[10005], n, m;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    int k = 0;
    for(int i = 0; i < m; i++){
        int temp;
        cin>>temp;
        for(int j = 0; j < temp; j++){
            b[k++] = i + 1;
        }
    }

    PolyHash hash_b(b, k);

    if(k > n){
        cout<<"NO"<<endl;
        return 0;
    }
    int maxPow = k;
    for(int i = 0; i <= n - k; i++){
        int tx[105], x = 0;
        for(int j = i; j < i + k; j++)
            tx[x++] = a[j];
        sort(tx, tx + k);
        PolyHash hash_temp(tx, k);
        if(hash_b(0, k, maxPow) == hash_temp(0, k, maxPow)){
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;

    return 0;
}