//Date: 24/09/19
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
 
typedef unsigned long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dp[55], arr[55];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int sum = 0, n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    for(int i = n - 1; i >= 0; i--){
        dp[i] = abs(arr[i] - dp[i+1]);
    }

    cout<<(sum - dp[0]) / 2<<" "<<(sum + dp[0]) / 2<<endl;

    return 0;
}