//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 998244353
#define MAX 200005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos) { return mask = mask | (1<<pos); }
bool checkBit(int mask, int pos) { return (bool)(mask & (1<<pos)); }

bool isPrime(int x)
{
    if(x == 1)
        return false;
    if(x == 2)
        return true;
    if(x % 2 == 0)
        return false;
    for(int i = 3; i * i <= x; i++) {
        if(x % i == 0)
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test, n;

    cin>>test;

    while(test--) {
        cin>>n;
        vector<int> div;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                div.pb(i);
                if(n / i != i)
                    div.pb(n / i);
            }
        }
        div.pb(n);

        sort(div.begin(), div.end());

        if(div.size() == 3 && isPrime(div[0]) && isPrime(div[1])) {
            for(int i = 0; i < div.size(); i++)
                cout<<div[i]<<" ";
            cout<<endl;
            cout<<1<<endl;
            continue;
        }


        map<int, int> mp;
        vector<int> primes;

        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                while(n % i == 0) {
                    n /= i;
                }
                primes.pb(i);
            }
        }
        if(n != 1)
            primes.pb(n);

        int pSz = primes.size();

        vi ans(pSz);

        for(int i = 0; i < primes.size(); i++) {
            int p1 = primes[i], p2 = primes[(i + 1) % pSz];
            for(int j = 0; j < div.size(); j++) {
                if(!mp[div[j]] && div[j] % p1 == 0 && div[j] % p2 == 0) {
                    mp[div[j]] = 1;
                    ans[i] = div[j];
                    break;
                }
            }
        }

        for(int i = 0; i < pSz; i++) {
            mp[primes[i]] = 1;
            cout<<primes[i]<<" ";
            for(int j = 0; j < div.size(); j++) {
                if(!mp[div[j]] && div[j] % primes[i] == 0) {
                    mp[div[j]] = 1;
                    cout<<div[j]<<" ";
                }
            }
            if(pSz > 1) {
                cout<<ans[i]<<" ";
            }
        }
        cout<<endl;
        cout<<0<<endl;
    }

    return 0;
}

 
