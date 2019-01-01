#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 100005
using namespace std;

typedef long long ll;
const int inf = 1<<28;

ll arr[MAX];

int main()
{
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%lld", &arr[i]);
        }

        int l = 0, r = n - 1;

        ll Max = -1000000000, ans;

        while(l < r){
            if(arr[l] <= arr[r]){
                ans = (r - l) * arr[l];
                if(ans > Max)
                    Max = ans;
                l++;
            }
            else{
                ans = (r - l) * arr[r];
                if(ans > Max)
                    Max = ans;
                r--;
            }
        }

        printf("%lld\n", Max);
    }

    return 0;
}
