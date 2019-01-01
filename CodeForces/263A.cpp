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
    int idxi, idxj, x;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &x);
            if(x == 1){
                idxi = i;
                idxj = j;
            }
        }
    }

    int result = abs(2 - idxi) + abs(2 - idxj);

    printf("%d\n", result);

    return 0;
}
