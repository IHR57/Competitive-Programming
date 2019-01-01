#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    int test, caseno = 1;
    ll H, L;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &H, &L);
        int lg = (int) log2(L);
        if((1LL<<lg) != L)
            lg++;
        ll sum = L;
        for(int i = 0; i < lg; i++){
            sum += (1LL<<i);
        }
        if(H >= lg){
            sum += (H - lg) * L;
        }

        printf("Case %d: %lld\n", caseno++, sum);
    }

    return 0;
}
