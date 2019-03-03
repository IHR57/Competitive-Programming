#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define MAX 10010
using namespace std;

int mark[MAX], primes[1500], counter = 1;

void genSieve()
{
    int limit = sqrt(MAX + 1);

    mark[1] = 1;
    for(int i = 4; i < MAX; i += 2)
        mark[1] = 1;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

int main()
{
    int n;

    genSieve();

    int cs[counter+5];

    cs[0] = 0;

    //cout<<primes[counter - 1]<<endl;
    for(int i = 1; i < counter; i++){
        cs[i] = cs[i-1] + primes[i];
    }

    while(scanf("%d", &n) == 1){
        if(!n)
            break;
        int cnt = 0;
        for(int i = 1; i < counter; i++){
            for(int j = i; j < counter; j++){
                int sum = cs[j] - cs[i-1];
                if(sum == n)
                    cnt++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
