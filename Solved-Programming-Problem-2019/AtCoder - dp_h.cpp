/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
//Problem Link: https://atcoder.jp/contests/dp/tasks
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX][MAX];
char ch[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int h, w;

    cin>>h>>w;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin>>ch[i][j];
        }
    }

    for(int i = 1; i <= h; i++){
        if(ch[i][1] == '#'){
            break;
        }
        else
            dp[i][1] = 1;
    }
    for(int i = 1; i <= w; i++){
        if(ch[1][i] == '#')
            break;
        dp[1][i] = 1;
    }
    dp[1][1] = 0;
    for(int i = 2; i <= h; i++){
        for(int j = 2; j <= w; j++){
            if(ch[i][j] == '#')
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout<<dp[h][w]<<endl;


    return 0;
}
