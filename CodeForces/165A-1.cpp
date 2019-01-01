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
    int n, data[210][5];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &data[i][j]);        //take input
        }
    }

    int left, right, upper, down, superCentral = 0;
    for(int i = 0; i < n; i++){
        left = right = upper = down = 0;
        for(int j = 0; j < n; j++){
            if(data[j][0] > data[i][0] && data[j][1] == data[i][1])
                upper++;
            else if(data[j][0] < data[i][0] && data[j][1] == data[i][1])
                down++;
            else if(data[j][0] == data[i][0] && data[j][1] < data[i][1])
                left++;
            else if(data[j][0] == data[i][0] && data[j][1] > data[i][1])
                right++;
        }
        if(upper >= 1 && down >= 1 && left >= 1 && right >= 1)
            superCentral++;
    }

    printf("%d\n", superCentral);

    return 0;
}
