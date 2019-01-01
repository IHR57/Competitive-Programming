#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 10000005
using namespace std;

bool mark[MAX];

void genSieve()
{
    memset(mark, false, sizeof(mark));

    int limit = sqrt(MAX) + 1;

    mark[1] = true;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = true;
    mark[2] = false;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2){
                    mark[j] = true;
                }
            }
        }
    }
}

void solve(int n)
{
    if(n == 4){
        printf("2 2\n");
    }
    else{
        for(int i = 3; ; i += 2){
            if(!mark[i] && !mark[n-i]){
                printf("%d %d\n", i, n - i);
                break;
            }
        }
    }
}
int main()
{
    int n;

    genSieve();

    while(scanf("%d", &n) == 1){
        if(n < 8){
            printf("Impossible.\n");
        }
        else{
            if(n % 2 != 0){
                printf("2 3 ");
                n -= 5;
            }
            else{
                printf("2 2 ");
                n -= 4;
            }
            solve(n);
        }
    }

    return 0;
}
