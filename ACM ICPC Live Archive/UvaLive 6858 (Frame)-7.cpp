#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 1000005
using namespace std;

int main()
{
    int x, y, k, n;

    while(scanf("%d %d", &x, &y) == 2){
        scanf("%d", &k);

        for(int i = 0; i < k; i++){
            scanf("%d", &n);
            int u = y, l = x - 1, r = x - 1, d = y - 2;
            if(n > min(x, y)){
                printf("NO\n");
                continue;
            }
            if(u % n > 2){
                printf("NO\n");
                continue;
            }
            else if(u % n == 1)
                l++;
            else if(u % n == 2)
                l++, r++;
            if(l % n > 1){
                printf("NO\n");
                continue;
            }
            if(l % n == 1)
                d++;
            if(d % n == n - 1){
                r--;
                d++;
            }
            if(d % n != 0){
                printf("NO\n");
                continue;
            }
            if(r % n != 0){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }
        }
    }

    return 0;
}
