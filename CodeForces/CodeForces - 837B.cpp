//Problem ID: CodeForces - 837B (Flag of Berland)
//Programmer: IQBAL HOSSAIN     Description: Brute Force/Implementation
//Date: 15/05/19
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

char grid[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    bool isOk = true;
    if(n % 3 == 0){
        int k = n / 3;
        if(grid[0][0] != grid[k][0] && grid[k][0] != grid[k*2][0] && grid[0][0] != grid[k*2][0]){
            for(int x = 0; x < n; x += k){
                for(int i = x; i < x + k; i++){
                    for(int j = 0; j < m; j++){
                        if(grid[i][j] != grid[x][0])
                            isOk = false;
                    }
                }
            }
        }
        else
            isOk = false;
    }
    else
        isOk = false;
    if(isOk){
        cout<<"YES"<<endl;
        return 0;
    }
    if(m % 3 == 0){
        isOk = true;
        int k = m / 3;
        if(grid[0][0] != grid[0][k] && grid[0][k] != grid[0][k*2] && grid[0][0] != grid[0][k*2]){
            for(int x = 0; x < m; x += k){
                for(int i = 0; i < n; i++){
                    for(int j = x; j < x + k; j++){
                        if(grid[i][j] != grid[0][x]){
                            isOk = false;
                        }
                    }
                }
            }
        }
        else{
            isOk = false;
        }
    }
    (isOk) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    return 0;
}
