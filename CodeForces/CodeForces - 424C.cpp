//Problem ID: CodeForces - 424C
//Programmer: IQBAL HOSSAIN     Description: Math
//Date: 06/01/19
#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int n, p[MAX], xorSum[MAX];

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
    }

    xorSum[0] = 0;
    for(int i = 1; i < MAX; i++){
        xorSum[i] = (xorSum[i-1] ^ i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if((n / i) % 2 == 0){
            ans ^= (p[i] ^ xorSum[n % i]);
        }
        else{
            ans ^= (p[i] ^ xorSum[i-1] ^ xorSum[n % i]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
