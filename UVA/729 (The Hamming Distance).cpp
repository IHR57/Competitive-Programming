#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int number[50], position[50], arr[20005][100];
int n, k, idx;

void init()
{
    for(int i = 1; i <= n; i++)
        position[i] = 0;
}
void combination(int pos, int last)
{
    if(pos == k + 1){
        init();
        for(int i = 1; i <= k; i++){
            position[number[i]] = 1;
        }
        for(int i = 1; i <= n; i++)
            arr[idx][i] = position[i];
        idx++;

        return;
    }

    for(int i = last + 1; i <= n - k + pos; i++){
        number[pos] = i;
        combination(pos + 1, i);
    }
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        idx = 1;
        combination(1, 0);      //call combination

        for(int i = idx - 1; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                printf("%d", arr[i][j]);
            }
            printf("\n");
        }
        if(test)
            printf("\n");
    }

    return 0;
}
