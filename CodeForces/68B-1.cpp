#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 10005
#define INF 2147483647
#define EPS 1e-8
using namespace std;

int n, k, arr[MAX];

double maximumEqual(int a, int b)
{
    double supply, mid;
    double low = 0.0;
    double high = 100000.0;

    while(high - low >= EPS){
        mid = low + (high - low) / 2.0;
        supply = 0.0;
        for(int i = 0; i < n; i++){
            if(arr[i] >= mid){
                supply += (arr[i] - mid) * (100.0 - k) / 100.0;
            }
            else{
                supply -= (mid - arr[i]);
            }
        }

        if(supply >= 0.0)
            low = mid;
        else
            high = mid;
    }

    return mid;
}

int main()
{
    scanf("%d %d", &n, &k);

    int Min = INF, Max = -INF;

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        Min = min(Min, arr[i]);     //Minimum and maximum element
        Max = max(Max, arr[i]);
    }

    double result = maximumEqual(Min, Max);

    printf("%0.9lf\n", result);

    return 0;
}
