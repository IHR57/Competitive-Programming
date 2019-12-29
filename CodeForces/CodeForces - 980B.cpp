//Problem ID: CodeForces - 980B (Marlin)
//Programmer: IQBAL HOSSAIN     Description: Constructive Algorithms
//Date: 23/04/19
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

char grid[4][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    cout<<"YES"<<endl;
    if(k == 1){
        grid[1][n/2] = '#';
    }
    else if(k == 3){
        grid[1][n/2] = grid[1][n/2 +1] = grid[1][n/2 - 1] = '#';
    }
    else if(k % 2 == 0){
        int idx = 1;
        while(k > 0){
            grid[1][idx] = '#';
            grid[2][idx] = '#';
            k -= 2;
            idx++;
        }
    }
    else{
        k -= 3;
        int idx = 1;
        while(k > 0){
            grid[1][idx] = '#';
            grid[2][idx] = '#';
            k -= 2;
            idx++;
        }
        grid[1][idx] = '#';
        idx++;
        grid[1][idx] = '#';
        grid[2][idx] = '#';
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != '#'){
                cout<<".";
            }
            else
                cout<<"#";
        }
        cout<<endl;
    }

    cout<<endl;

    return 0;
}
