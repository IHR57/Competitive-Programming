#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 100000005
using namespace std;

typedef long long lint;

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    int count = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(((i * i) + j == n) && i + (j * j) == m)
                count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
