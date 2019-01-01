#include <bits//stdc++.h>
using namespace std;

int kadane(int* element, int row)
{
    int maxSum = INT_MIN, sum=0;
    int finish = -1;

    for(int i=0; i<row; i++){
        sum+=element[i];
        if(sum<0){
            sum = 0;
        }
        else if(sum>maxSum){
            maxSum = sum;
            finish = i;
        }
    }

    if(finish!=-1){
        return maxSum;
    }

    //special case:: if all element are zero;
    maxSum = element[0];

    for(int i=1; i<row; i++){
        if(element[i]>maxSum){
            maxSum = element[i];
        }
    }

    return maxSum;
}

int main()
{
    int n, input[110][110], temp[110], sum, maxSum;

    scanf("%d", &n);
        maxSum = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &input[i][j]);
            }
        }

        for(int left = 0; left<n; left++){
            memset(temp, 0, sizeof(temp));
            for(int right = left; right<n; right++){
                for(int i=0; i<n; i++){
                    temp[i]+=input[i][right];
                }

                sum = kadane(temp, n);

                if(sum>maxSum){
                    maxSum = sum;
                }
            }
        }

        printf("%d\n", maxSum);
    //}

    return 0;
}
