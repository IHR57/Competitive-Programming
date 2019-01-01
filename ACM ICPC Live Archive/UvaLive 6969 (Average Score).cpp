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
    int test, n, m, value;
    double avg1, avg2;

    scanf("%d",  &test);

    while(test--){
        scanf("%d %d", &n, &m);
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n - 1; i++){
            scanf("%d", &value);
            sum1 += value;
        }
        avg1 = (double) sum1 / (n - 1);
        sum2 = 0;
        for(int i = 0; i < m; i++){
            scanf("%d", &value);
            sum2 += value;
        }
        avg2 = (double) sum2 / m;

        //cout<<avg1<<" "<<avg2<<endl;
        int Min, Max;

        Min = floor(avg2) + 1;
        Max = ceil(avg1 - 1);

        printf("%d %d\n", Min, Max);
    }

    return 0;
}
