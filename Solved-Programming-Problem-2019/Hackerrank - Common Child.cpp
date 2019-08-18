#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 5005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

string s1, s2;
int dp[MAX][MAX];

int solve(int i, int j)
{
    if(i >= s1.size() || j >= s2.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ret = 0;
    if(s1[i] == s2[j]){
        ret = 1 + solve(i + 1, j + 1);
    }
    else{
        ret = max(solve(i + 1, j), solve(i, j + 1));
    }

    return dp[i][j] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cin>>s1>>s2;
    memset(dp, -1, sizeof(dp));
    
    cout<<solve(0, 0)<<endl;

    return 0;
}
