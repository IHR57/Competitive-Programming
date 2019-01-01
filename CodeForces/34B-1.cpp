#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 110
using namespace std;

const int INF = 1 << 28;

int main()
{
    int n, m, data[MAX], num;

    scanf("%d %d", &n, &m);

    int j = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        data[j++] = -num;
    }

    sort(data, data+n);

    int sum = 0, Max = -INF;
    for(int j = n - 1; j >= n - m; j--){
        sum += data[j];
        if(sum > Max)
            Max = sum;
    }

    if(Max < 0)
        Max = 0;

    printf("%d\n", Max);

    return 0;
}
