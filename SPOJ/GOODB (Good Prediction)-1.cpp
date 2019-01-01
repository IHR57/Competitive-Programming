#include <bits/stdc++.h>
#define MAX 305
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll pascal[MAX][MAX];

int main()
{
    for(int i = 0; i < MAX; i++){
        pascal[i][i] = 1, pascal[i][0] = 1;
        for(int j = 1; j < i; j++){
            pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]) % MOD;
        }
    }

    int n, w, t, r;

    scanf("%d %d %d %d", &n, &w, &t, &r);

    ll result1 = pascal[w+t][t];
    ll result2 = pascal[w+t+r][r];

    printf("%lld\n", (result1 * result2) % MOD);

    return 0;
}
