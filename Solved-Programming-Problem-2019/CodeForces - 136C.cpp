//Problem ID: CodeForces - 136C (Replacement)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 07/01/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    int n, arr[MAX], Max = -1, idx;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > Max){
            Max = arr[i];
            idx = i;
        }
    }

    if(Max == 1){
        arr[idx] = 2;
    }
    else{
        arr[idx] = 1;
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
