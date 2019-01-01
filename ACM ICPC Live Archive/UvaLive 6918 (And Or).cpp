#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 100005
using namespace std;

typedef unsigned long long ll;

int main()
{
    ll a, b;
    int test, caseno = 1;

    scanf("%d", &test);
    while(test--){
        scanf("%lld %lld", &a, &b);
        int bit1 = (int) log2(b) + 1, flag = 0;
        int bit2 = (int) log2(a) + 1;
        ll div = 2, sumOR = 0, sumAND = 0;
        if(a == b){
            flag = 1;
        }
        if(b - a >= 1)
            sumOR++;
        for(int i = bit1 - 1, j = 1; i >= 1; i--, j++){
            ll temp = (ll) pow(2, j);
            //cout<<temp<<endl;
            ll x = a / temp, y = b / temp;
            if(x != y){
                sumOR += (ll) pow(2, j);
            }
            else if(x == y){
                if(x % 2 != 0){
                    sumOR += (ll) pow(2, j);
                }
            }
        }
        for(int i = bit2 - 1, j = 1; i >= 1; i--, j++){
            ll temp = (ll) pow(2, j);
            //cout<<temp<<endl;
            ll x = a / temp, y = b / temp;
            if(x == y){
                if(x % 2 != 0){
                    sumAND += (ll) pow(2, j);
                }
            }
        }
        if(flag)
            printf("Case %d: %lld %lld\n", caseno++, a, a);
        else
            printf("Case %d: %lld %lld\n", caseno++, sumOR, sumAND);
    }
    return 0;
}
