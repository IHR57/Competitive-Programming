#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#define MAX 100005
using namespace std;

int main()
{
    int n, sum  = 0;

    scanf("%d", &n);

    int x;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        sum += x;
    }

    int count = 0;
    for(int i = 1; i <= 5; i++){
        if( (sum + i) % (n + 1) != 1)
            count++;
    }

    printf("%d\n", count);

    return 0;
}
