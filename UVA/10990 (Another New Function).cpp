#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 2000010
using namespace std;

int phi[MAX], depth[MAX];
bool mark[MAX];

void SievePhi()
{
    for(int i = 1; i < MAX; i++)
        phi[i] = i;

    mark[1] = 1;        //1 is not prime

    for(int i = 2; i < MAX; i++){
        if(!mark[i]){
            for(int j = i; j < MAX; j += i){
                mark[j] = 1;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
int main()
{
    int test, n, m;
    long long int sum;

    SievePhi();     //generate all phi in range of 1 - 2*10^6
    scanf("%d", &test);     //number of test case

    depth[1] = 0;
    for(int i = 2; i < MAX; i++){
        depth[i] = depth[phi[i]] + 1;       //number of steps required before it reaches 1;
    }

    while(test--){
        sum = 0;
        scanf("%d %d",&m, &n);
        for(int i = m; i <= n; i++){
            sum += depth[i];
        }

        printf("%lld\n", sum);
    }

    return 0;
}
