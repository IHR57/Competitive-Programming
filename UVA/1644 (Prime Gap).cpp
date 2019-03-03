#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define MAX 1300000
using namespace std;

bool mark[MAX];

void genSieve()
{
    memset(mark, false, sizeof(mark));

    int limit = sqrt(MAX + 1);
    mark[1] = true;

    for(int i = 4; i < MAX; i += 2)
        mark[i] = true;

    mark[2] = false;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = true;
            }
        }
    }
}

int main()
{
    int n;
    genSieve();

    while(scanf("%d", &n) == 1){
        if(!n)  break;

        int ans = 0;
        int temp = n;

        if(!mark[n]){
            printf("0\n");
            continue;
        }
        while(mark[temp]){
            ans++;
            temp--;
        }
        temp = n + 1;
        while(mark[temp]){
            ans++;
            temp++;
        }

        printf("%d\n", ans + 1);
    }

    return 0;
}
