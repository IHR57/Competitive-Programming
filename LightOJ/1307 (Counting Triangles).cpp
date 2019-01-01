#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

int main()
{
    int test, caseNo = 1, n, arr[MAX];
    int value, idx;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        sort(arr, arr + n);

        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                value = arr[i] + arr[j];
                idx = lower_bound(arr, arr+n, value) - arr;
                sum += (idx - j - 1);
            }
        }

        printf("Case %d: %d\n", caseNo++, sum);
    }

    return 0;
}
