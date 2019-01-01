#include <bits/stdc++.h>
#define MAX 105
#define EPS 1e-10
using namespace std;

int main()
{
    int test, caseNo = 1, n;
    double arr[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%lf", &arr[i]);
        }

        for(int i = n - 2; i >= 0; i--){            //solving backward
            int k = min(6, n - i - 1);
            //cout<<k<<endl;
            double result = 0;
            for(int j = i + 1; j < i + 1 + k; j++){
                result += arr[j];
            }
            arr[i] += (result / (double) k);         //we've to take current gold
        }

        printf("Case %d: %0.8lf\n", caseNo++, arr[0] + EPS);
    }

    return 0;
}
