#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    int test, caseNo = 1, arr[MAX], n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int allPositive = 1, allNegative = 1, negative = 0, sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(arr[i] > 0)
                allNegative = 0;
            if(arr[i] < 0)
                allPositive = 0, negative++;;
            sum += abs(arr[i]);
        }

        if(allPositive){
            int g = __gcd(sum, n);
            printf("Case %d: %d/%d\n", caseNo++, sum/g, n/g);
        }
        else if(allNegative){
            printf("Case %d: inf\n", caseNo++);
        }
        else{
            int g = __gcd(sum, n - negative);
            printf("Case %d: %d/%d\n", caseNo++, sum/g, (n-negative)/g);
        }
    }

    return 0;
}
