#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 1005
using namespace std;

int main()
{
    int n, m, a[MAX], b[MAX], x, y;

    while(scanf("%d %d", &n, &m) == 2){
        for(int i = 0; i < n; i++){
            scanf("%d %d", &a[i], &b[i]);
        }

        int x, y, t, k;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d",  &x, &y, &t);
            int cnt = 0;
            for(int j = 0; j < n; j++){
                int d = b[j] - a[j];
                int temp = t / d;
                if(temp % 2 == 0){
                    k = a[j] + (t % d);
                }
                else
                    k = b[j] - (t % d);
                if(k >= x && k <= y)
                    cnt++;
            }
            printf("%d\n", cnt);
        }
    }

    return 0;
}
