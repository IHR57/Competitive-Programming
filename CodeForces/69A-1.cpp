#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, x, sum0 = 0, sum1 = 0, sum2 = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &x);
            if(j == 0)  sum0 += x;
            else if(j == 1)     sum1 += x;
            else    sum2 += x;
        }
    }

    if(sum0 == 0 && sum1 == 0 && sum2 == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
