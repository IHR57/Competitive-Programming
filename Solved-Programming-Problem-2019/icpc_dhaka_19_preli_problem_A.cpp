//Date: 06/11/19
//Problem Link: https://algo.codemarshal.org/contests/icpc-dhaka-19-preli/problems/A
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

    PolyHash(const char *s) : pref1(strlen(s) + 1, 0), pref2(strlen(s) + 1, 0){
        int n = strlen(s);
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
int PolyHash::base((int)129);  
std::vector<ll> PolyHash::p1;
std::vector<ull> PolyHash::p2;

char str[2000005], pat[2000005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int test, k, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%s %s %d", str, pat, &k);
        PolyHash hash_a(str), hash_b(pat);
        int n = strlen(str), m = strlen(pat);
        printf("Case %d: ", caseno++);
        if(m > n){
            printf("0\n");
            continue;
        }
        int maxPow = n, res = 0;
        for(int i = 0; i <= n - m; i++){
            int x = i, cnt = 0, j = 0;
            bool flag = true;
            while(true){
                if(j == m){
                    //cout<<cnt<<endl;
                    if(cnt > k)
                        flag = false;
                    break;
                }
                if(cnt > k){
                    flag = false;
                    break;
                }
                //cout<<x<<" "<<j<<endl;
                int low = 0, high = m - j, mid, ans = 0;
                while(low <= high){
                    mid = (low + high + 1) >> 1;
                    if(hash_a(x, mid, maxPow) == hash_b(j, mid, maxPow)){
                        ans = mid;
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
                x += (ans + 1);
                j += (ans + 1);
                if(j >= m + 1)
                    break;
                cnt++;

            }
            if(flag)
                res++;
        }
        printf("%d\n", res);
    }

    return 0;
}