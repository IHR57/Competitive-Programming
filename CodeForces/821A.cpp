#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, a[60][60], idx[60][60];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
            idx[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int number = a[i][j];
            if(number > 1){
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        if(l != j && k != i){
                            if(a[i][l] + a[k][j] == number)
                                idx[i][j] = 1;
                        }
                    }
                }
            }
        }
    }

    int flag = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(idx[i][j] != 1){
                flag = 0;
                break;
            }
        }
    }

    if(flag)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
