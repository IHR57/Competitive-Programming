//Problem ID: CodeForces - 1060C (Maximum SubRectangle)
//Programmer: IQBAL HOSSAIN     Description: Binary Search/DP/Two Pointers
//Date: 14/04/19
#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

int dp[MAX*MAX];
int a[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, x;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }
    cin>>x;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += a[j];
            dp[sum] = max(dp[sum], j - i + 1);
        }
    }
    for(int i = 1; i < MAX*MAX; i++){
        dp[i] = max(dp[i], dp[i-1]);
    }

    int Max = 0;
    for(int i = 0; i < m; i++){
        int sum = 0;
        for(int j = i; j < m; j++){
            sum += b[j];
            int rem = x / sum;
            if(rem >= MAX * MAX)
                rem = MAX * MAX - 1;
            int res = (j - i + 1) * dp[rem];
            Max = max(Max, res);
        }
    }

    cout<<Max<<endl;

    return 0;
}
