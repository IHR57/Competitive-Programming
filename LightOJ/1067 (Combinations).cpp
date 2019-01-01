#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 1000005
using namespace std;

typedef long long lint;
lint factorial[MAX];

lint bigMod(lint a, lint b)         //big Mod
{
    if(b == 0)
        return 1;
    lint x = bigMod(a, b/2);
    x = (x * x) % 1000003;
    if(b % 2 == 1){
        x = (x * a) % 1000003;
    }

    return x;
}

int main()
{
    factorial[0] = 1;

    for(int i = 1; i < 1000001; i++){       //pre generate all factorial up to 10^6
        factorial[i] = (i * factorial[i-1]) % 1000003;
    }

   int test, cases = 1;
   lint n, r;

   scanf("%d", &test);

   while(test--){
       scanf("%lld %lld", &n, &r);
       lint temp = (factorial[r] * factorial[n-r]) % 1000003;
       lint result = (factorial[n] * bigMod(temp, 1000001)) % 1000003;      //modular inverse
       printf("Case %d: %lld\n", cases++, result);
   }

   return 0;
}
