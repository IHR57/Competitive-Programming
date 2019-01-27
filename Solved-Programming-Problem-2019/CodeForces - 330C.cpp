#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int grid[MAX][MAX], row[MAX], col[MAX];

int main()
{
    char str[MAX];
    int n;

    scanf("%d",  &n);

    for(int i = 0; i < n ; i++){
        scanf("%s", str);
        for(int j = 0; j < n; j++){
            if(str[j] == 'E')
                grid[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                row[i]++;
            }
            if(grid[j][i] == 1){
                col[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(row[i] == n && col[j] == n){
                printf("-1\n");
                return 0;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(!grid[i][j]){
                cnt++;
            }
        }
        if(cnt)     ans++;
    }

    if(ans == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]){
                    printf("%d %d\n", i + 1, j + 1);
                    break;
                }
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                if(!grid[j][i]){
                    printf("%d %d\n", j + 1, i + 1);
                    break;
                }
            }
        }
    }

    return 0;
}
