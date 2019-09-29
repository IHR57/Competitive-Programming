//Problem ID: CodeForces - 698A (Vacations)
//Programmer: IQBAL HOSSAIN     Description: DP
//Date: 08/09/19
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

int dp[MAX][3], arr[MAX], n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    dp[0][0] = 0, dp[0][1] = (check(arr[0], 0)) ? 1 : 0, dp[0][2] = (check(arr[0], 1)) ? 1 : 0;
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
        if(check(arr[i], 0)){
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
        }
        else
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        if(check(arr[i], 1)){
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
        }
        else
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
    }

    cout<<(n - max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])))<<endl;

    return 0;
}
