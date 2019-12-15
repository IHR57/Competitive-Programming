//Date: 22/11/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(int mask, int pos) { return (bool) (mask & (1<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

int arr[MAX];
vector<int> v[MAX*10];
vector<ll> d;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        for(int j = 1; j * j <= arr[i]; j++){
            if(arr[i] % j == 0){
                if(i >= j)
                    v[j].pb(i);
                if(arr[i] / j != j)
                    if(arr[i] / j <= i)
                        v[arr[i]/j].pb(i);
            }
        }

    }

    ll ans = n;
    for(int i = 0; i <= n; i++)
        d.pb((ll)i);

    for(int i = 2; i <= MAX * 10; i++){
        if(v[i].empty())
            break;
        ll temp = 0;
        vector<ll> t;
        t.pb(0);
        for(int j = 0; j < v[i].size(); j++){
            int idx = lower_bound(v[i-1].begin(), v[i-1].end(), v[i][j]) - v[i-1].begin();
            temp = (temp + d[idx]) % MOD;
            t.pb(temp);
        }
        d = t;
        ans = (ans + temp) % MOD;
    }

    cout<<ans<<endl;

    return 0;
}