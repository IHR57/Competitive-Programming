//Problem ID: AtCoder - dp_i (Coins)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 12/07/19
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_i
#include <bits/stdc++.h>
#define MAX 3005
using namespace std;
 
double dp[MAX][MAX], p[MAX];
int n, visited[MAX][MAX];

double solve(int pos, int cnt)
{
    if(pos >= n){
        if(cnt > (n / 2)){
            return 1.0;
        }
        else
            return 0;
    }
    if(visited[pos][cnt] != -1)
        return dp[pos][cnt];
    visited[pos][cnt] = 1;

    double ret1 = p[pos] * solve(pos + 1, cnt + 1);
    double ret2 = (1.0 - p[pos]) * solve(pos + 1, cnt);
    return dp[pos][cnt] = ret1 + ret2;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    memset(visited, -1, sizeof(visited));
    
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>p[i];
    }

    double result = solve(0, 0);

    cout<<setiosflags(ios::fixed)<<setprecision(12);
    cout<<result<<endl;

    return 0;
}