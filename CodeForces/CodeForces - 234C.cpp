/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
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
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX];
int dp[2][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        if(arr[i] > 0){
            dp[0][i] = dp[0][i-1] + 1;
            dp[1][i] = dp[1][i-1];
        }
        else if(arr[i] < 0){
            dp[1][i] = dp[1][i-1] + 1;
            dp[0][i] = dp[0][i-1];
        }
        else{
            dp[0][i] = dp[0][i-1] + 1;
            dp[1][i] = dp[1][i-1] + 1;
        }
    }

    int ans = n;
    for(int i = 2; i <= n - 1; i++){
        int temp;
        if(arr[i] < 0){
            temp = dp[0][i];
            temp += (dp[1][n] - dp[1][i]);
            ans = min(ans, temp);
        }
        else if(arr[i] > 0){
            temp = dp[0][i-1];
            temp += (dp[1][n] - dp[1][i-1]);
            ans = min(ans, temp);
        }
    }

    cout<<ans<<endl;

    return 0;
}
