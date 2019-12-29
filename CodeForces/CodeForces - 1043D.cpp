//Date: 16/12/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 1000000007
#define MAX 300005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(ll mask, ll pos) { return (bool) (mask & (1LL<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

int cs[12][MAX], arr[12][MAX], idx[12][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;

    cin>>n>>m;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin>>arr[i][j];
            cs[i][j] = cs[i][j-1] + arr[i][j];
            idx[i][arr[i][j]] = j;
        }
    }
    int l = 1, r = 1;
    ll ans  = 0;

    while(true){
        int sum = cs[1][r] - cs[1][l-1];
        int len = r - l + 1;
        //cout<<l<<" "<<r<<endl;
        bool flag = true;
        for(int i = 2; i <= m; i++){
            int x = idx[i][arr[1][l]];
            //cout<<x<<endl;
            if(x + len > n + 1){
                flag = false;
                break;
            }
            if(cs[i][x+len-1] - cs[i][x-1] != sum){
                flag = false;
                break;
            }
        }
        if(flag){
            ans += (ll) (r - l + 1);
            r++;
        }
        else{
            l++;
        }
        if(l > n || r > n)
            break;
    }

    cout<<ans<<endl;

    return 0;
}