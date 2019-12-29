//Date: 31/10/19
//Problem Link: https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=43&id_problem=286
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
    string str;

    cin>>str;
    int n = str.size();
    str += str;

    PolyHash::base = 257;
    //create hashing object
    PolyHash hash(str);
        
    int maxPow = 2 * n;

    vector<int> v;

    for(int i = 0; i < n; i++){
        v.pb(i);
    }

    int p1 = 0;

    stable_sort(v.begin(), v.end(), [&] (const int p1, const int p2){
        int low = 0, high = n, mid, ans;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            if(hash(p1, mid, maxPow) == hash(p2, mid, maxPow)){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans < n && str[p1+ans] < str[p2+ans];
    });
    
    int idx = find(v.begin(), v.end(), 0) - v.begin();
    cout<<idx + 1<<endl;

    string temp;
    for(int i = 0; i < v.size(); i++){
        temp += str[v[i] + n - 1];
    }

    cout<<temp<<endl;

    return 0;
}
