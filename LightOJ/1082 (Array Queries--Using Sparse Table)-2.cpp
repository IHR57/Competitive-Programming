#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <math.h>
#define MAX 100005
using namespace std;

const int INF = 1<<28;
const int k = 16;
int arr[MAX], ST[MAX][k+1];

int main()
{
    int n, queryNumber, a, b;
    int test, cases = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &queryNumber);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

            for(int i = 0; i < n; i++)
                ST[i][0] = arr[i];

        for(int j = 1; j <= k; j++){
            for(int i = 0; i <= n - (1<<j); i++){
                ST[i][j] = min(ST[i][j-1] , ST[i + (1<<(j-1))][j-1]);
            }
        }
        printf("Case %d:\n", cases++);
        while(queryNumber--){
            scanf("%d %d", &a, &b);
            a--; b--;
            int answer = INF;
            for(int j = k; j >= 0; j--){
                if(a + (1<<j) - 1 <= b){
                    answer = min(answer, ST[a][j]);
                    a += 1<<j;
                }
            }
            printf("%d\n", answer);
        }
    }

    return 0;
}

