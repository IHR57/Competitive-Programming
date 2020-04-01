//Date: 31/03/2020
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
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
int dp[105][105][105][2];
int n, arr[105];
 
int solve(int pos, int odd, int even, int prev)
{
    if(pos >= n)
        return 0;
    if(dp[pos][odd][even][prev] != -1)
        return dp[pos][odd][even][prev];
 
    int ret = 2e9;
    if(pos == 0){
        if(arr[pos] == 0){
            if(even)
                ret = min(ret, solve(pos + 1, odd, even - 1, 0));
            if(odd)
                ret = min(ret, solve(pos + 1, odd - 1, even, 1));
        }
        else{
            ret = solve(pos + 1, odd, even, arr[pos] % 2);
        }
    }
    else{
        if(arr[pos] == 0){
            if(even)
                ret = min(ret, (prev == 1) + solve(pos + 1, odd, even - 1, 0));
            if(odd)
                ret = min(ret, (prev == 0) + solve(pos + 1, odd - 1, even, 1));
        }
        else{
            ret = min(ret, (prev != arr[pos] % 2) + solve(pos + 1, odd, even, arr[pos] % 2));
        }
    }
 
    return dp[pos][odd][even][prev] = ret;
 
}
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    cin>>n;
 
    int odd = (n + 1) >> 1, even = n >> 1;
 
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] != 0 && (arr[i] & 1))
            odd--;
        else if(arr[i] != 0 && !(arr[i] & 1))
            even--;
    }
 
    //cout<<odd<<" "<<even<<endl;
    memset(dp, -1, sizeof(dp));
    int res = solve(0, odd, even, 0);
 
    cout<<res<<endl;
 
    return 0;
}