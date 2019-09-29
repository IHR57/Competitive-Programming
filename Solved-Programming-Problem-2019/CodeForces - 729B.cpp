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

int dp[2][MAX][MAX], arr[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;

    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>arr[i][j];
            dp[0][j][i] = dp[0][j][i-1] + arr[i][j];
            dp[1][i][j] = dp[1][i][j-1] + arr[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] == 0){
                int cs = dp[0][j][i-1];
                if(cs)
                    ans++;
                cs = dp[0][j][n] - dp[0][j][i];
                if(cs)
                    ans++;
                cs = dp[1][i][j-1];
                if(cs)
                    ans++;
                cs = dp[1][i][m] - dp[1][i][j];
                if(cs)
                    ans++;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
