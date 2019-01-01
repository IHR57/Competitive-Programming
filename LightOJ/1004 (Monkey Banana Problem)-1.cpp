#include <bits//stdc++.h>
using namespace std;

vector<int>Matrix[210];
int dp[210][210];
int n, x;

int call(int row, int col)
{
    if(row>=0 && row<(2*n-1) && col>=0 && col<Matrix[row].size()){
        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        int ret = -1;

        ret = max(ret, call(row+1, col)+Matrix[row][col]);
        if(row<n-1)
            ret = max(ret, call(row+1, col+1)+Matrix[row][col]);
        else if(row>=n-1)
            ret = max(ret, call(row+1, col-1)+Matrix[row][col]);

        return dp[row][col] = ret;
    }
    else
        return 0;       //if outside the table
}

int main()
{
    int test, cases = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
       // memset(Matrix, 0, sizeof(Matrix));
        /*input Format:
            7
            6 4
            2 5 10
            9 8 12 2
            2 12 7
            8 2
            10
        */
        for(int i=0; i<n; i++){
            Matrix[i].clear();
            for(int j=0; j<=i; j++){
                scanf("%d", &x);
                Matrix[i].push_back(x);
            }
        }
        int k = n-1;
        for(int i=n; i<(2*n-1); i++){
            Matrix[i].clear();
            for(int j=0; j<k; j++){
                scanf("%d", &x);
                Matrix[i].push_back(x);
            }
            k--;
        }

        /*for(int i=0; i<2*n-1; i++){
            for(int j=0; j<n; j++){
                printf("%d ", Matrix[i][j]);
            }
            printf("\n");
        }*/

        memset(dp, -1, sizeof(dp));

        //int value = call(0, 0);         //start searching from first cell

        printf("Case %d: %d\n", cases++, call(0, 0));
    }

    return 0;
}
