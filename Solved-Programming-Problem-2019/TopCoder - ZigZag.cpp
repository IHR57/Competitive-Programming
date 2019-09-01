//Problem ID: TopCoder - ZigZag 
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

class ZigZag
{
    public:
        int longestZigZag(vector<int> sequence)
        {
            int n = sequence.size();
            dp[0][0] = 1, dp[0][1] = 1;
            for(int i = 1; i < sequence.size(); i++){
                dp[i][0] = dp[i-1][0];
                for(int j = i - 1; j >= 0; j--){
                    if(sequence[j] > sequence[i])
                        dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
                dp[i][1] = dp[i-1][1];
                for(int j = i - 1; j >= 0; j--){
                    if(sequence[j] < sequence[i]){
                        dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                    }
                }
            }

            return max(dp[n-1][0], dp[n-1][1]);
        }
};

// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     ZigZag obj = ZigZag();
//     vector<int> v;
//     int n, val;
//     cin>>n;
//     for(int i = 0; i < n; i++){
//         cin>>val;
//         v.pb(val);
//     }

//     cout<<obj.longestZigZag(v)<<endl;
    
//     return 0;
// }
