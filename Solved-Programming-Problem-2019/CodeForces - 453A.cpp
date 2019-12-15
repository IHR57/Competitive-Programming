//Date: 24/11/19
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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    double x = 0, res = 0.0;
    int n, m;

    cin>>m>>n;

    for(int i = 1; i <= m; i++){
        double tx = pow(1.0 * i / (double) m, n);
        res += (double) i * (tx - x);
        x = tx;
    }

    cout<<fixed<<setprecision(12);
    cout<<res<<endl;

    return 0;
}