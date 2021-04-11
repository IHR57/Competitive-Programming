//Date: 25/01/20
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<ll> num;
vector<ii> arr;
ll cnt[2*MAX], res[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll n, l, r;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>l>>r;
        num.pb(l);
        num.pb(r + 1);
        arr.pb(mk(l, r));
    }

    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());

    for(int i = 0; i < n; i++){
        int x = lower_bound(num.begin(), num.end(), arr[i].ff) - num.begin();
        cnt[x]++;
        int y = lower_bound(num.begin(), num.end(), arr[i].ss + 1) - num.begin();
        cnt[y]--;
    }

    for(int i = 1; i < 2 * n; i++){
        cnt[i] += cnt[i-1];
    }

    for(int i = 1; i < 2 * n; i++){
        res[cnt[i-1]] += num[i] - num[i-1];
    }

    for(int i = 1; i <= n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;


    return 0;
}