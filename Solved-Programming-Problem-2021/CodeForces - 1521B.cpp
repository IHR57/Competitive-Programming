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
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define all(v)          v.begin(),v.end()
#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.rbegin(),v.rend())
#define REV(v)          reverse(v.begin(),v.end())
#define INF 2147483647
#define MOD 998244353
#define MAX 300005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef pair<ll, ll> LL;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

void solve()
{
    int n;

    cin>>n;

    vi arr(n);

    int mn = INF, idx;
    REP(i, n) {
        cin>>arr[i];
        if(arr[i] < mn) {
            mn = arr[i];
            idx = i;
        }
    }

    int cnt = 0;
    vi prm;

    for(int i = mn + 1; ; i++) {
        if(isPrime(i)) {
            prm.pb(i);
            cnt++;
            if(cnt >= 1)
                break;
        }
    }

    cout<<n - 1<<endl;

    for(int i = idx + 1; i < n; i++) {
        int x;
        if(i - 1 >= 0 && arr[i-1] != prm[0])
            x = prm[0];
        else
            x = mn;
        arr[i] = x;
        cout<<idx + 1<<" "<<i + 1<<" "<<mn<<" "<<x<<endl;
    }

    for(int i = idx - 1; i >= 0; i--) {
        int x;
        if(i + 1 < n && arr[i+1] != prm[0])
            x = prm[0];
        else
            x = mn;
        arr[i] = x;
        cout<<idx + 1<<" "<<i + 1<<" "<<mn<<" "<<x<<endl;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

