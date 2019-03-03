#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

int main()
{
    int test, arr[10][10];

    scanf("%d", &test);

    while(test--){
        for(int i = 1; i <= 9; i += 2){
            for(int j = 1; j <= i; j += 2){
                scanf("%d", &arr[i][j]);
            }
        }

        int k = 1;
        for(int i = 1; i <= 7; i += 2){
            int temp = arr[7][k] - (arr[9][i] + arr[9][i+2]);
            arr[9][i+1] = temp / 2;
            k += 2;
        }

        for(int i = 8; i >= 1; i--){
            for(int j = 1; j <= i; j++){
                if(i % 2 == 0){
                    arr[i][j] = arr[i+1][j] + arr[i+1][j+1];
                }
                else{
                    if(j % 2 == 0){
                        arr[i][j] = arr[i+1][j] + arr[i+1][j+1];
                    }
                }
            }
        }

        for(int i = 1; i <= 9; i++){
            for(int j = 1; j < i; j++){
                printf("%d ", arr[i][j]);
            }
            printf("%d\n", arr[i][i]);
        }
    }

    return 0;
}
