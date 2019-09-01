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

int arr[MAX], n;
int dp[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    dp[0] = max(0, arr[0]);
    if(n >= 2)
        dp[1] = max(arr[1], dp[0]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-2], max(dp[i-1], dp[i-2] + arr[i]));
    }
    if(n == 1)
        cout<<dp[0]<<endl;
    else
        cout<<max(dp[n-1], dp[n-2])<<endl;
    
    return 0;
}
