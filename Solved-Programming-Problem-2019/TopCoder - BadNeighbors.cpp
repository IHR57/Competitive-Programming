//Problem ID: TopCoder - BadNeighbors 
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 28/08/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 1e17
#define MOD 1000000007
#define MAX 55
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dp[MAX][2];

class BadNeighbors
{
    public:
        int maxDonations(vector <int> donations)
        {
            dp[1][0] = 0, dp[1][1] = donations[0];
            int n = donations.size(), ans;
            for(int i = 2; i <= n - 1; i++){
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][1];
                dp[i][1] = max(dp[i][1], dp[i-1][0] + donations[i-1]);
                //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            }
            ans = max(dp[n-1][0], dp[n-1][1]);
            if(n == 1)
                return ans;
            memset(dp, 0, sizeof(dp));
            dp[2][0] = 0, dp[2][1] = donations[1];
            for(int i = 3; i <= n; i++){
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][1];
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] + donations[i-1]);
                //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            }
            ans = max(ans, max(dp[n][0], dp[n][1]));

            return ans;
        }
};

// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     BadNeighbors obj = BadNeighbors();
//     vector<int> v;
//     int n, val;
//     cin>>n;
//     for(int i = 0; i < n; i++){
//         cin>>val;
//         v.pb(val);
//     }

//     cout<<obj.maxDonations(v)<<endl;
    
//     return 0;
// }
