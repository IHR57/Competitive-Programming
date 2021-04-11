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

int nr, ng, nb;
vector<ll> red, green, blue;
ll ans;

ll cal(ll a, ll b, ll c)
{
    return (a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a);
}

//void checkIt(int tr, int i, int tb)
//{
//    if(tr > 0 && tb > 0)
//        ans = min(ans, cal(red[tr-1], green[i], blue[tb-1]));
//    if(tr > 0 && tb < nb)
//        ans = min(ans, cal(red[tr-1], green[i], blue[tb]));
//    if(tr < nr && tb > 0)
//        ans = min(ans, cal(red[tr], green[i], blue[tb-1]));
//    if(tr < nr && tb < nb)
//        ans = min(ans, cal(red[tr], green[i], blue[tb]));
//}

solve(vector<ll> r, vector<ll> g, vector<ll> b)
{
    for(int i = 0; i < r.size(); i++){
        int tg = lower_bound(g.begin(), g.end(), r[i]) - g.begin();
        int tb = upper_bound(b.begin(), b.end(), r[i]) - b.begin();
        if(tg == g.size() || tb == 0)
            continue;
        tb--;
        ans = min(ans, cal(r[i], g[tg], b[tb]));
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test;

    cin>>test;

    while(test--){
        cin>>nr>>ng>>nb;
        int val;

        red.clear(), blue.clear(), green.clear();

        for(int i = 0; i < nr; i++){
            cin>>val;
            red.pb(val);
        }

        for(int i = 0; i < ng; i++){
            cin>>val;
            green.pb(val);
        }

        for(int i = 0; i < nb; i++){
            cin>>val;
            blue.pb(val);
        }

        sort(red.begin(), red.end());
        sort(green.begin(), green.end());
        sort(blue.begin(), blue.end());

        ans = 9223372036854775807;


        solve(red, green, blue);
        solve(red, blue, green);
        solve(green, red, blue);
        solve(green, blue, red);
        solve(blue, red, green);
        solve(blue, green, red);

        cout<<ans<<endl;
    }

    return 0;
}
