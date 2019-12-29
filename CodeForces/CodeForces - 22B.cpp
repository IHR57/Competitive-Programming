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

int grid[30][30], dp[30][30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    char ch;

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>ch;
            grid[i][j] = (ch - 48);
        }
    }

    for(int i = 1; i <= m; i++)
        dp[1][i] = grid[1][i];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] += grid[i][j] + dp[i-1][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= m; j++){
            dp[i][j] += dp[i][j-1];
        }
    }   


    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int x = 1; x <= n; x++){
                for(int y = 1; y <= m; y++){
                    if(x >= i && y >= j){
                        int temp = dp[x][y] - dp[x-i][y] - dp[x][y-j] + dp[x-i][y-j];
                        if(temp == 0){
                            ans = max(ans, 2 * (i + j));
                        }
                    }
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
