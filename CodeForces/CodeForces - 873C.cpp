//Problem ID: CodeForces - 873C (Strange Game on Matrix)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 12/05/19
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int cs[MAX][MAX], grid[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;

    cin>>n>>m>>k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>grid[i][j];
            cs[j][i] = cs[j][i-1] + grid[i][j];
        }
    }
    int totalScore = 0, operation = 0;
    for(int i = 1; i <= m; i++){
        int Max = 0, cnt = 0, t = 0;
        for(int j = 1; j <= n; j++){
            if(grid[j][i] == 1){
                int ans = cs[i][min(j + k - 1, n)] - cs[i][j-1];
                if(ans > Max){
                    Max = ans;
                    t = cnt;
                }
                cnt++;
            }
        }
        totalScore += Max, operation += t;
    }

    cout<<totalScore<<" "<<operation<<endl;

    return 0;
}
