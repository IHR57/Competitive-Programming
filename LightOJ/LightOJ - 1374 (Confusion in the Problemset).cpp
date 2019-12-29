//Problem ID: LightOJ - 1374 (Confusion in the Problemset)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 19/03/19
//Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1374
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int counter[MAX];

int main()
{
    int test, caseno = 1, n, val;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        memset(counter, 0, sizeof(counter));

        int flag  = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &val);
            if(val < n){
                counter[val]++;
                if(counter[val] > 2)
                    flag = 1;
            }
            else
                flag = 1;
        }

        for(int i = 0; i < (n + 1) / 2; i++){
            if(counter[i] == 2 || counter[n-i-1] == 2 || (counter[i] == 1 && counter[n-i-1] == 1))
                continue;
            else{
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("Case %d: no\n", caseno++);
        else
            printf("Case %d: yes\n", caseno++);
    }

    return 0;
}
