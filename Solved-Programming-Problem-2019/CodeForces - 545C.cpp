#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dp[MAX][2];     //0 - fall left, 1 - fall right
int h[MAX], x[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>x[i]>>h[i];
    }

    dp[0][0] = 1, dp[0][1] = 0;
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if(x[i] - h[i] > x[i-1])
            dp[i][0] = dp[i-1][0] + 1;
        if(x[i] - h[i] > x[i-1] + h[i-1])
            dp[i][0] = max(dp[i][0] , dp[i-1][1] + 1);
        if(i == n - 1 || x[i] + h[i] < x[i+1]){
            dp[i][1] = max(dp[i-1][0] + 1, dp[i-1][1] + 1);
        }
    }

    cout<<max(dp[n-1][0], dp[n-1][1])<<endl;
    return 0;
}
