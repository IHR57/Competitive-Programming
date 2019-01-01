#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define MAX 1000005
using namespace std;

typedef long long int lint;

bool isPrime(lint n)
{
    if(n == 2)
        return true;
    else if(n % 2 == 0)
        return false;

    int limit = sqrt(n + 1);

    for(int i = 3; i <= limit; i += 2){
        if(n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int test;
    lint n;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        if(isPrime(n))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
