//Date: 27/11/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 1000000007
#define MAX 1000005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(int mask, int pos) { return (bool) (mask & (1<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll n;

    cin>>n;

    ll g = n;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            g = __gcd(g, i);
            if(n / i != i){
                g = __gcd(g, n / i);
            }
        }
    }

    cout<<g<<endl;
    

    return 0;
}