#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int number[20], arr[20], used[100], result, flag;

void permute(int pos, int n)
{
    if(pos == n + 1){
        //for(int i = 1; i <= n; i++)
          //  printf("%d ", number[i]);
        //printf("\n");
        for(int i = 1; i <= 3; i++){        //all possible combination
            for(int j = 1; j <= 3; j++){
                for(int k = 1; k <= 3; k++){
                    for(int l = 1; l <= 3; l++){
                        result = 0;
                        if(i == 1)      result = number[1] + number[2];
                        else if(i == 2) result = number[1] - number[2];
                        else if(i == 3) result = number[1] * number[2];

                        if(j == 1)      result = result + number[3];
                        else if(j == 2) result = result - number[3];
                        else if(j == 3) result = result * number[3];

                        if(k == 1)      result = result + number[4];
                        else if(k == 2) result = result - number[4];
                        else if(k == 3) result = result * number[4];

                        if(l == 1)      result = result + number[5];
                        else if(l == 2) result = result - number[5];
                        else if(l == 3) result = result * number[5];
                        //printf("Result: %d\n", result);
                        if(result == 23){
                            flag = 1;
                        }
                    }
                }
            }
        }
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!used[i]){
            used[i] = 1;
            number[pos] = arr[i];
            permute(pos + 1, n);
            used[i] = 0;
        }
    }
}

int main()
{
    int first, second, third, fourth, fifth;

    while(scanf("%d %d %d %d %d", &first, &second, &third, &fourth, &fifth) == 5){
        if(first == 0 && second == 0 && third == 0 && fourth == 0 && fifth == 0)
            break;
        arr[1] = first, arr[2] = second, arr[3] = third, arr[4] = fourth, arr[5] = fifth;

        //sort(arr+1, arr+6);

        memset(used, 0, sizeof(used));
        //result = 0;
        flag = 0;       //set flag zero

        //depthFirst(1, arr[i]);      //call dfs
        permute(1, 5);

        if(flag)            //if we find result = 23
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}
