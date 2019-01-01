#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int dp[MAX][MAX];

int main()
{
    int test;
    vector<int> Agnes, Tom;

    scanf("%d", &test);

    while(test--){
        int value, v, c = 0, cnt = 0, Max = 0;
        while(scanf("%d", &v) == 1){
            if(!v)  break;
            if(c == 0)
                Agnes.push_back(v);
            else
                Tom.push_back(v);
            c++;
            while(scanf("%d", &value) == 1){
                if(!value)  break;
                if(cnt == 0){
                    Agnes.push_back(value);
                }
                else{
                    Tom.push_back(value);
                }
            }
            cnt++;

            memset(dp, -1, sizeof(dp));
            for(int i = 0; i <= Agnes.size(); i++){
                for(int j = 0; j <= Tom.size(); j++){
                    if(i == 0 || j == 0)
                        dp[i][j] = 0;
                    else if(Agnes[i-1] == Tom[j-1])
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            if(dp[Agnes.size()][Tom.size()] > Max){
                Max = dp[Agnes.size()][Tom.size()];
            }
            Tom.clear();
        }
        printf("%d\n", Max);
        Agnes.clear();
    }

    return 0;
}
