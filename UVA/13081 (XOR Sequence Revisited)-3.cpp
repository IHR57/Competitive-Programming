#include <iostream>
#include <vector>
#include <cstdio>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    int test;
    ll l, r;

    /*ll dp[MAX];

    dp[0] = 1;
    for(int i = 1; i < MAX; i++){
        dp[i] = (dp[i-1] ^ i);
    }

    for(int i = 0; i < 1000; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;*/


    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &l, &r);
        ll diff = (r - l);
        if(diff >= 2){
            printf("0\n");
        }
        else if(l == r){
            ll tmp;
            if(l == 0)
                tmp = 1;
            else if(l == 1)
                tmp = 0;
            else if(l % 4 == 0)
                tmp = (l + 1);
            else if(l % 4 == 1)
                tmp = 0;
            else if(l % 4 == 2)
                tmp = l;
            else if(l % 4 == 3)
                tmp = 1;

            ll result = tmp;
            printf("%lld\n", result);
        }
        else{
            ll tmp, tmp1;
            if(l == 0)
                tmp = 1;
            else if(l == 1)
                tmp = 0;
            else if(l % 4 == 0)
                tmp = (l + 1);
            else if(l % 4 == 1)
                tmp = 0;
            else if(l % 4 == 2)
                tmp = l;
            else if(l % 4 == 3)
                tmp = 1;

            if(r == 0)
                tmp1 = 1;
            else if(r == 1)
                tmp1 = 0;
            else if(r % 4 == 0)
                tmp1 = (r + 1);
            else if(r % 4 == 1)
                tmp1 = 0;
            else if(r % 4 == 2)
                tmp1 = l;
            else if(r % 4 == 3)
                tmp1 = 1;

            printf("%lld\n", tmp & tmp1);
        }
    }

    return 0;
}
