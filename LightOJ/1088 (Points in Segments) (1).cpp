#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int data[100010];

int main()
{
    int test, cases=1, a, b, x, y, n, query;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &query);

        for(int i=0; i<n; i++){
            scanf("%d", &data[i]);
        }

        printf("Case %d:\n", cases++);

        for(int i=0; i<query; i++){
            scanf("%d %d", &a, &b);

            a=lower_bound(data, data+n, a)-data;
            b=upper_bound(data+a, data+n, b)-data;

            printf("%d\n", b-a);
        }
    }

    return 0;
}
