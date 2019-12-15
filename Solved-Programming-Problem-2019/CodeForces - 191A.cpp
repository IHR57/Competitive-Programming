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

const int inf = 1<<28;
int dp[26][26];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int n;
    string str;

    cin>>n;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++){
        cin>>str;
        int len = str.size();
        int idx1 = str[0] - 'a', idx2 = str[len-1] - 'a';
        for(int j = 0; j < 26; j++){
            if(dp[j][idx1] != -1){
                dp[j][idx2] = max(dp[j][idx2], dp[j][idx1] + len);
            }
        }
        dp[idx1][idx2] = max(dp[idx1][idx2], len);
    }

    int res = 0;
    for(int i = 0; i < 26; i++){
        res = max(res, dp[i][i]);
    }

    cout<<res<<endl;

    return 0;
}
