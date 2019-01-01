#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 1 << 28;

int main()
{
    int n, arr[110];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int Min = INF, idx1, idx2;

    if(n == 2){
        printf("1 2\n");
    }
    else{
        for(int i = 0; i < n; i++){
            int ans = abs(arr[i] - arr[(i + 1) % n]);
            if(ans < Min){
                Min = ans;
                idx1 = i + 1;
                idx2 = (i + 2) % n;
            }
        }

        printf("%d %d\n", idx1, idx2);
    }

    return 0;
}
