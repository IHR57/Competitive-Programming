#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 25
using namespace std;

typedef long long lint;

int main()
{
    lint result;
    int n, arr[MAX], cases = 1;

    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        lint maxValue = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                result = 1;
                for(int k = i; k <= j; k++){
                    result = result * arr[k];
                }
                if(result >= maxValue)
                    maxValue = result;
            }
        }

        printf("Case #%d: The maximum product is %lld.\n\n", cases++, maxValue);
    }

    return 0;
}
