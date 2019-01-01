#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define MAX 100000005
using namespace std;

int status[MAX / 32];

bool check(int n, int pos)
{
    return (bool) (n & (1 << pos));
}

int Set(int n, int pos)
{
    return n = n | ( 1 << pos);
}

void genSieve()
{
    int sqrtN = sqrt(MAX + 1);

    for(int i = 3; i <= sqrtN; i += 2){
        if(check(status[i / 32], i % 32) == 0){
            for(int j = i * i; j < MAX; j += i * 2){
                status[j / 32] = Set(status[j / 32], j % 32);       //mark as not prime
            }
        }
    }

    int count = 0;
    printf("2\n");
    for(int i = 3; i < MAX; i += 2){
        if(check(status[i / 32], i % 32) == 0){
            count++;
            if(count == 100){
                printf("%d\n", i);
                count = 0;
            }
        }
    }
}

int main()
{
    //freopen("output.txt", "w", stdout);

    genSieve();

    return 0;
}
