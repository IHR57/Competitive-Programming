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

vector<int> red(MAX), green(MAX), mixed(MAX);
int x, y, a, b, c;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y, a, b, c;

    cin>>x>>y>>a>>b>>c;

    int val;
    for(int i = 0; i < a; i++){
        cin>>red[i];
    }
    sort(red.begin(), red.end());

    for(int i = 0; i < b; i++){
        cin>>green[i];
    }
    sort(green.begin(), green.end());

    for(int i = 0; i < c; i++){
        cin>>mixed[i];
    }
    sort(mixed.begin(), mixed.end());

    ll ans = 0;

    for(int i = x + y; i > 0; i--){
        int r = (red.empty() || x <= 0) ? 0 : red.back();
        int g = (green.empty() || y <= 0) ? 0 : green.back();
        int m = mixed.empty() ? 0 : mixed.back();

        if(r >= m && r >= g){
            ans += (ll) red.back();
            red.pop_back();
            x--;
        }
        else if(g >= m && g >= r){
            ans += (ll) green.back();
            green.pop_back();
            y--;
        }
        else{
            ans += (ll) mixed.back();
            mixed.pop_back();
        }
    }

    cout<<ans<<endl;

    return 0;
}
