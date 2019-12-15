//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int grid[50][50];

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

void bruteforce()
{
    int k = 6, ans = 0;
    for(int i = 0; i < (1 << k); i++){
        memset(grid, 0, sizeof(grid));
        for(int j = 0; j < (1 << k); j++){
            for(int m = 0; m < (1 << k); m++){
                for(int x = 0; x < k; x++){
                    if(check(i, x))
                        grid[0][x] = 1;
                    else
                        grid[0][x] = 0;
                    if(check(j, x))
                        grid[1][x] = 1;
                    else
                        grid[1][x] = 0;
                    if(check(m, x))
                        grid[2][x] = 1;
                    else
                        grid[2][x] = 0;
                }

                bool flag = true;
            for(int x = 0; x < 3; x++){
                for(int y = 0; y < k; y++){
                    int cnt = 0;
                    for(int z = 0; z < 4; z++){
                        int tx = x + fx[z];
                        int ty = y + fy[z];
                        if(tx >= 0 && tx < 3 && ty >= 0 && ty < k){
                            if(grid[tx][ty] == grid[x][y])
                                cnt++;
                        }
                    }
                    if(cnt >= 2)
                        flag = false;

                }
            }
            if(flag)
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}

ll dp[MAX], cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    dp[0] = 2, dp[1] = 2, dp[2] = 4;
    cs[0] = 0, cs[1] = 2, cs[2] = 4, cs[3] = 8;
    for(int i = 3; i <= MAX; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        cs[i+1] = (cs[i] + dp[i]) % MOD;
    }

    int n, m;

    cin>>n>>m;

    ll res = (dp[n] + cs[m-1]) % MOD;

    cout<<res<<endl;

    return 0;
}
