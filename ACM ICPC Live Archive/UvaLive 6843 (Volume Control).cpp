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
vector<bool> a(30000*30000+5);
ll ans[MAX];

int main()
{
    ll sum = 1;
    for(int i = 1; i < 30001; i++){
        for(int j = 1; j <= i; j++){
            int temp = i * j;
            if(!a[temp]){
                sum++;
                a[temp] = true;
            }
        }
        ans[i] = sum;
    }

    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }

    return 0;
}
