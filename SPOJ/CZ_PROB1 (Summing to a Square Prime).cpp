#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int primes[MAX / 10], mark[MAX], counter = 0;

void genSieve()
{
    int limit = sqrt(MAX + 1);
    mark[1] = 1;

    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2){
                    mark[j] = 1;
                }
            }
        }
    }
}

int n, k, dp[MAX][5], coin[5];

int main()
{
    genSieve();

    vector<int> v;
    int way[8000];

    v.push_back(2);
    for(int i = 0; i < counter; i++){
        if(primes[i] % 4 == 1){
            v.push_back(primes[i]);
        }
    }


    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < k; i++){
            coin[i] = i + 1;
        }

        memset(dp, -1, sizeof(dp));

        int sp = v[n-1];

        for(int i = 0; i < k; i++)
            dp[0][i] = 1;

        for(int i = 1; i <= sp; i++){
            for(int j = 0; j < k; j++){
                int x = (i - coin[j] >= 0) ? dp[i-coin[j]][j] : 0;
                int y = (j >= 1) ? dp[i][j-1] : 0;
                dp[i][j] = x + y;
            }
        }

        printf("%d\n", dp[sp][k-1]);
    }

    return 0;
}
