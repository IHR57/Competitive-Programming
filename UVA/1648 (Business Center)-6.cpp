#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 100005
using namespace std;

const int inf = 1<<28;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;

    while(scanf("%d %d", &n, &m) == 2){
        int u, v;
        int ans = inf;
        for(int i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            int low = 0, high = n, mid;
            while(low <= high){
                mid = (low + high) >> 1;
                int temp = (u * mid) - (n - mid) * v;
                if(temp > 0){
                    high = mid - 1;
                    if(temp < ans)
                        ans = temp;
                }
                else{
                    low = mid + 1;
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
