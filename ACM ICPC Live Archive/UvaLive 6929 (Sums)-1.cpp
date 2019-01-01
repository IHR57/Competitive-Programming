#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

int main()
{
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int lg = (int) log2(n);
        if((1<<lg) == n){
            printf("IMPOSSIBLE\n");
            continue;
        }
        if(n % 2 != 0){
            printf("%d = %d + %d\n", n, n/2, n/2 + 1);
        }
        else{
            for(int i = 3; ; i++){
                int temp = (i * (i + 1)) / 2;
                int value = n - temp;
                if(value % i == 0){
                    int number = value / i;
                    printf("%d = %d", n, number + 1);
                    for(int j = number + 2; j <= number + i; j++){
                        printf(" + %d", j);
                    }
                    printf("\n");
                    break;
                }
            }
        }
    }

    return 0;
}
