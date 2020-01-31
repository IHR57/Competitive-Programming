//Date: 09/01/20
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 1005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, e, d;

    cin>>n>>d>>e;

    int ans = INF;
    for(int i = 0; i <= (n / 30 + 1); i++){
        int x = i * d, y;
        int rem = n - x;
        if(rem < 0)
            break;
        int euro = rem / e;
        y = 0;
        if(euro >= 5){
            int t = euro / 5;
            y = 5 * t * e;
        }
        ans = min(ans, n - (x + y));
    }

    cout<<ans<<endl;

    return 0;
}