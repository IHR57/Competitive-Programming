#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 100005
using namespace std;

int main()
{
    int m, n;

    while(scanf("%d %d", &m, &n) == 2){
        int cnt = 0;
        for(int i = 0; i <= m; i++){
            for(int j = i; j <= m; j++){
                for(int k = j; k <= m; k++){
                    if(i * i + j * j == k * k)
                        cnt++;
                }
            }
        }

        int result = cnt + (m + 1) * (n - 2);
        printf("%d\n", result);
    }

    return 0;
}
