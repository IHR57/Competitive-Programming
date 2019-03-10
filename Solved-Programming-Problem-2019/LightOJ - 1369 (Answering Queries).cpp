//Problem ID: LightOJ - 1369 (Answering Queries)
//Programmer: IQBAL HOSSAIN     Description: Mathematics
//Date: 05/03/19
//Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1369
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll arr[MAX];

int main()
{
    int test, caseno = 1, n, q;
    ll sum, cs;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &q);
        sum = 0, cs = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(i){
                sum += (cs - (arr[i] * i));
            }
            cs += arr[i];
        }

        printf("Case %d:\n", caseno++);

        for(int i = 0; i < q; i++){
            int cmnd, pos, val;
            scanf("%d", &cmnd);
            if(cmnd){
                printf("%lld\n", sum);
            }
            else{
                scanf("%d %d", &pos, &val);
                ll diff = abs(val - arr[pos]);
                if(val <= arr[pos]){
                    sum += (pos * diff);
                    sum -= ((n - pos - 1) * diff);
                }
                else{
                    sum -= (pos * diff);
                    sum += ((n - pos - 1) * diff);
                }
                arr[pos] = val;
            }
        }
    }

    return 0;
}
