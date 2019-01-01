#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

typedef long long lint;

int main()
{
    double harmonic[MAX];
    double sum = 0;

    //we cannot use 10^8 memory so we have to apply some technique
    //we store sum of 1 to 1000 in harmonic[0], 1001 to 2000 in harmonic[1] etc.
    for(int i = 0; i < MAX; i++){       //we have to pre-calculate result
        for(int j = i * 1000 + 1; j <= (i + 1) * 1000; j++){
            sum += (double)(1.0 / j);
        }
        harmonic[i] = sum;
    }

    int test, cases = 1, n;
    double result;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int div = n / 1000;
        int rem = n % 1000;
        if(div >= 1){
            result = harmonic[div-1];
        }
        else
            result = 0;

        for(int i = div * 1000 + 1; i <= n; i++){       //we need 1000 iteration in worst case
            result += (double) (1.0 / i);
        }
        printf("Case %d: %0.10lf\n", cases++, result + 1e-10);
    }

    return 0;
}
