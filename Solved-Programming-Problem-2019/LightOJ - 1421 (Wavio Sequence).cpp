//Problem ID: LightOJ - 1421 (Wavio Sequence)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (LIS)
//Date: 05/03/19
//Problem ID: http://www.lightoj.com/volume_showcode.php?sub_id=1427867
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

const int inf = 1<<28;

int I[MAX];
vector<int> arr;
int n;

void LIS(int dp[])
{
    for(int i = 0; i < n; i++){
        I[i] = inf;
    }

    int lisLength = 0;
    for(int i = 0; i < n; i++){
        int idx = lower_bound(I, I + n, arr[i]) - I;
        I[idx] = arr[i];
        if(idx > lisLength){
            lisLength = idx;
        }
        dp[i] = lisLength + 1;
    }
}

int main()
{
    int test, caseno = 1, val;
    int dp1[MAX], dp2[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &val);
            arr.push_back(val);
        }

        LIS(dp1);
        reverse(arr.begin(), arr.end());
        LIS(dp2);

        int ans = 1;
        for(int i = 0; i < n; i++){
            if(dp1[i] == dp2[n-i]){
                ans = max(ans, dp1[i] + dp2[n-i] - 1);
            }
        }

        printf("Case %d: %d\n", caseno++, ans);
        arr.clear();
    }

    return 0;
}
