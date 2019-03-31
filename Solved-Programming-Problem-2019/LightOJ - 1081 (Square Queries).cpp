//Problem ID: LightOJ - 1081 (Square Queries)
//Programmer: IQBAL HOSSAIN     Description: Data Structures (Sparse Table)
//Date: 28/03/19
//Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1081
#include <bits/stdc++.h>
#define MAX 505
using namespace std;

int arr[MAX][MAX], n;
int ST[MAX][11][MAX];

void buildST()          //Sparse Table for RMQ
{
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++)
            ST[j][0][i] = i;

        for(int k = 1; (1 << k) <= n; k++){
            for(int i = 0; i + (1 << k) <= n; i++){
                int x = ST[j][k-1][i];
                int y = ST[j][k-1][i+(1<<(k-1))];
                ST[j][k][i] = (arr[j][x] >= arr[j][y]) ? x : y;
            }
        }
    }
}

int RMQ(int r, int i, int j)
{
    int k = log2(j - i + 1);
    int x = ST[r][k][i];
    int y = ST[r][k][j-(1<<k)+1];

    return (arr[r][x] >= arr[r][y]) ? x : y;
}

int main()
{
    int test, caseno = 1, query;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &query);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &arr[i][j]);
            }
        }

        buildST();

        int I, J, S;

        printf("Case %d:\n", caseno++);

        while(query--){
            scanf("%d %d %d", &I, &J, &S);
            I--, J--;
            int Max = -1;
            for(int i = I; i < I + S; i++){
                //cout<<i<<" "<<J<<" "<<J + S - 1<<endl;
                Max = max(Max, arr[i][RMQ(i, J, J+S-1)]);
            }
            printf("%d\n", Max);
        }
    }

    return 0;
}
