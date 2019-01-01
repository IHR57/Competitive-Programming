#include <bits/stdc++.h>
#define MAX 10005
#define MOD 100000007
using namespace std;

int main()
{
    int test, caseNo = 1, coin[105], temp[MAX], way[MAX], k, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &coin[i]);
        }

        memset(temp, 0, sizeof(temp));
        memset(way, 0, sizeof(way));

        way[0] = 1;

        sort(coin, coin + n);

        for(int i = 0; i < n; i++){
            for(int j = coin[i]; j <= k; j++){
                way[j] = (temp[j] + way[j-coin[i]]) % MOD;
            }
            for(int j = 0; j <= k; j++)
                temp[j] = way[j];
        }

        printf("Case %d: %d\n", caseNo++, way[k]);
    }

    return 0;
}
