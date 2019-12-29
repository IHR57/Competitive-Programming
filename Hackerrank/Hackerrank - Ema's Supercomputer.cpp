#include <bits/stdc++.h>
#define MAX 21
using namespace std;

char grid[MAX][MAX];

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>grid[i][j];
        }
    }

    int area = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x = 0;
            while(grid[i+x][j] == 'G' && grid[i-x][j] == 'G' && grid[i][j+x] == 'G' && grid[i][j-x]== 'G'){
                grid[i+x][j] = grid[i-x][j] = grid[i][j+x] = grid[i][j-x] = 'g';
                for(int k = 1; k <= n; k++){
                    for(int l = 1; l <= m; l++){
                        int y = 0;
                        while(grid[k+y][l] == 'G' && grid[k-y][l] == 'G' && grid[k][l+y] == 'G' && grid[k][l-y] == 'G'){
                            area  = max(area, (4 * x + 1) * (4 * y + 1));
                            y++;
                        }
                    }
                }
                x++;
            }
            x = 0;
            while(grid[i+x][j] == 'g' && grid[i-x][j] == 'g' && grid[i][j+x] == 'g' && grid[i][j-x] == 'g'){
                grid[i+x][j] = grid[i-x][j] = grid[i][j+x] = grid[i][j-x] = 'G';
                x++;
            }
        }
    }
    cout<<area<<endl;

    return 0;
}