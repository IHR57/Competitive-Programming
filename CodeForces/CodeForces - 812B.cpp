//Date: 07/10/19
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

int cell[50][200], n, m;
int dp[20][2], last = -1;
int FL[20][2];      //save first and last occurenc of 1 in i'th floor

int solve(int floor, int stairway)
{
    if(floor == last){
        if(stairway == 0)
            return FL[floor][1];
        else
            return m - FL[floor][0] + 1;
    }
    if(dp[floor][stairway] != -1)
        return dp[floor][stairway];

    int ret = INF;
    if(stairway == 0){
        int cnt = (FL[floor][1] == 0) ? 1 : 2 * FL[floor][1] + 1;
        ret = min(ret, cnt + solve(floor - 1, stairway));
        ret = min(ret, (m + 2) + solve(floor - 1, !stairway));
    }
    else{
        int cnt = (FL[floor][0] == 0) ? 1 : (m - FL[floor][0] + 1) * 2 + 1;
        ret = min(ret, cnt + solve(floor - 1, stairway));
        ret = min(ret, (m + 2) + solve(floor - 1, !stairway));
    }

    return dp[floor][stairway] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    char ch;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m + 2; j++){
            cin>>ch;
            cell[i][j] = (ch - 48);
        }
    }

    for(int i = 0; i <  n; i++){
        for(int j = 0; j < m + 2; j++){
            if(cell[i][j] == 1 && last == -1){
                last = i;
            }
            if(cell[i][j] == 1){
                if(FL[i][0] == 0){
                    FL[i][0] = FL[i][1] = j;
                }
                else
                    FL[i][1] = j;
            }
        }
    }


    if(last == -1){
        cout<<0<<endl;
        return 0;
    }
    memset(dp, -1, sizeof(dp));

    int res = solve(n - 1, 0);

    cout<<res<<endl;


    return 0;
}