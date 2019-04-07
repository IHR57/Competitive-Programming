//Problem ID: CodeForces - 611C (New Year and Domino)
//Programmer: IQBAL HOSSAIN     Description: DP/Implementation
//Date: 07/04/19
#include <bits/stdc++.h>
#define MAX 505
using namespace std;

int cs[MAX][MAX], grid[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int row, col, query;
    string str;

    cin>>row>>col;

    for(int i = 0; i < row; i++){
        cin>>str;
        for(int j = 0; j < col; j++){
            (str[j] == '.') ? grid[i+1][j+1] = 0 : grid[i+1][j+1] = 1;
        }
    }

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            int cnt = 0;
            if(grid[i][j] == 0 && j + 1 <= col && grid[i][j+1] == 0)
                cnt++;
            if(grid[i][j] == 0 && i + 1 <= row && grid[i+1][j] == 0)
                cnt++;
            cs[i][j] += cs[i][j-1] + cnt;
        }
    }

    cin>>query;

    int l1, r1, l2, r2;
    for(int i = 0; i < query; i++){
        cin>>l1>>r1>>l2>>r2;
        int ans = 0;
        for(int j = l1; j <= l2; j++){
            ans += cs[j][r2] - cs[j][r1-1];
            if(grid[j][r2] == 0 && r2 + 1 <= col && grid[j][r2+1] == 0)
                ans--;
        }
        for(int j = r1; j <= r2; j++){
            if(grid[l2][j] == 0 && l2 + 1 <= row && grid[l2+1][j] == 0)
                ans--;
        }

        cout<<ans<<endl;
    }

    return 0;
}
