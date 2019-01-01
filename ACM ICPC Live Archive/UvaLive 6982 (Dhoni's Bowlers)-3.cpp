#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    int test, n, m, x, a[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &n, &m, &x);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            a[i] %= m;
        }

        sort(a, a + n);

        ll sum = 0;

        for(int i = 0; i < n; i++){
            int tmp = upper_bound(a, a + n, x - a[i]) - a;
            sum += (ll) tmp;

            int idx2 = upper_bound(a, a + n, m + x - a[i]) - a;
            int idx1 = upper_bound(a, a + n, m - 1 - a[i]) - a;

            sum += (ll) (idx2 - idx1);
        }

        printf("%lld\n", sum);
    }

    return 0;
}
