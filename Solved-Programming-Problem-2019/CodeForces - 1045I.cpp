//Date: 26/11/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 1000000007
#define MAX 10005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(int mask, int pos) { return (bool) (mask & (1<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

map<int, int> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    vector<int> vs;
    string str;
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>str;
        int len = str.size();
        int x = 0;
        for(int j = 0; j < len; j++){
            x ^= (1 << (str[j] - 'a'));
        }
        vs.pb(x);
    }


    ll ans = 0;

    for(int i = 0 ; i < vs.size(); i++){
        ans += cnt[vs[i]];
        for(int j = 0; j < 26; j++){
            ans += cnt[vs[i] ^ (1<<j)];
        }
        cnt[vs[i]]++;
    }

    cout<<ans<<endl;

    return 0;
}