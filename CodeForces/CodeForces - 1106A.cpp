#include <bits/stdc++.h>
#define MAX 505
using namespace std;

int grid[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    char str[MAX];

    for(int i = 0; i < n; i++){
        cin>>str;
        for(int j = 0; j < n; j++){
            if(str[j] == 'X'){
                grid[i][j] = 1;
            }
            else{
                grid[i][j]  = 0;
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < n - 1; j++){
            if(grid[i][j]){
                if(grid[i-1][j-1] && grid[i-1][j+1] && grid[i+1][j-1] && grid[i+1][j+1]){
                    cnt++;
                }
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
