#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

const int inf = 1<<28;
int n, cost[MAX][5];

int main()
{
    int caseNo = 1;

    while(scanf("%d", &n) == 1){
        if(!n)  break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                scanf("%d", &cost[i][j]);
            }
        }
        cost[0][0] = inf;
        cost[0][2] += cost[0][1];

        int ans1, ans2, ans3, ans4;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < 3; j++){
                if(j == 0)
                    ans1 = inf;
                else    ans1 = cost[i-1][j-1];
                ans2 = cost[i-1][j];
                if(j == 2)
                    ans3 = inf;
                else    ans3 = cost[i-1][j+1];
                if(j == 0)  ans4 = inf;
                else    ans4 = cost[i][j-1];

                cost[i][j] += min(min(ans1, ans2), min(ans3, ans4));
            }
        }

        printf("%d. %d\n", caseNo++, cost[n-1][1]);
    }

    return 0;
}
