//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll binToDec(string str)
{
    reverse(str.begin(), str.end());
    ll x = 0;

    for(int i = 0; i < str.size(); i++) {
        x += (str[i] - 48) * (1LL<<i);
    }

    return x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test;
    ll n, m;

    cin>>test;

    while(test--) {
        cin>>n>>m;
        vector<ll> v;
        string str;
        for(int i = 0; i < n; i++) {
            cin>>str;
            ll num = binToDec(str);
            v.pb(num);
        }

        sort(v.begin(), v.end());

        ll mpos = ((1LL<<m) - n - 1) >> 1;

        for(int i = 0; i < v.size(); i++) {
            if(v[i] <= mpos) {
                mpos++;
            }
        }
        string ans = "";
        for(int i = 0; i < m; i++) {
            ans += (mpos % 2) + 48;
            mpos >>= 1;
        }

        reverse(ans.begin(), ans.end());

        cout<<ans<<endl;
    }

    return 0;
}
