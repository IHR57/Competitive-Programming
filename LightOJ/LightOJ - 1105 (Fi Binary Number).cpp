//Problem ID: LightOJ - 1105 (Fi Binary Number)
//Programmer: IQBAL HOSSAIN     Description: Bits
//Date: 05/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1105
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    vector<ll> fib;
    ll value, n;

    fib.push_back(1), fib.push_back(2);
    for(int i = 2; ; i++){
        value = fib[i-1] + fib[i-2];
        if(value > 1000000000)
            break;
        fib.push_back(value);
    }

    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        ll temp = n, fnumber = 0;
        while(true){
            int idx = upper_bound(fib.begin(), fib.end(), temp) - fib.begin();
            fnumber += (1LL<<(idx-1));
            if(fib[idx - 1] == temp){
                break;
            }
            temp -= fib[idx-1];
        }

        vector<int> bin;

        while(fnumber){
            bin.push_back(fnumber % 2);
            fnumber >>= 1;
        }

        reverse(bin.begin(), bin.end());

        printf("Case %d: ", caseno++);

        for(int i = 0; i < bin.size(); i++){
            printf("%d", bin[i]);
        }
        printf("\n");
        bin.clear();
    }

    return 0;
}
/*
there exists a nice pattern

1 digit FI Binary Number : 1
2 digit FI Binary Number : 10
3 digit FI Binary Number : 100, 101
4 digit FI Binary Number : 1000, 1001, 1010
5 digit FI Binary Number : 10000, 10001, 10010, 10100, 10101

so number of FI binary number in n digit will be fib(n)

we can use binary search to generate n'th FI Binary number
/*
