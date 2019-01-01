#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 1000100
using namespace std;

typedef long long lint;

lint primes[70000], counter = 0;
bool mark[MAX];

lint gcd(lint a, lint b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}
//generate prime
void genSieve()
{
    int limit = sqrt(MAX + 1);

    mark[1] = 1;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

lint Power(lint a, lint b)      //fast exponentiation
{
    if(b == 1)
        return a;
    if(b % 2 == 1)
        return a * Power(a, b - 1);
    lint temp;
    temp = Power(a, b/2);
    return temp * temp;
}

lint factorize(lint a, lint b, lint l)
{
    lint count1, count2, count, idx = 0;
    lint pf = primes[idx], ans = 1;

    while(pf * pf <= l){
        count1 = 0, count2 = 0, count = 0;
        while(a % pf == 0){
            a /= pf;
            count1++;
        }
        while(b % pf == 0){
            b /= pf;
            count2++;
        }

        lint temp = max(count1, count2);
        while(l % pf == 0){
            l /= pf;
            count++;
        }
        if(count > temp)     //we need the prime factor which is maximum
            ans *= Power(pf, count);
        else if(temp > count)
            ans *= Power(pf, temp);
        pf = primes[++idx];         //move to the next prime
    }
    if(a != 1 && a != b && a != l){
        ans *= a;
    }
    if(b != 1 && b != a && b != l)
        ans *= b;
    if(l != 1 && l != a && l != b)
        ans *= l;

    return ans;
}

int main()
{
    genSieve();

    int test, cases = 1;
    lint a, b;
    lint temp, L;       //L for lcm(a, b, c);

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld %lld", &a, &b, &L);
        //lint gcdofAB = gcd(a, b);      //gcd of a and b
        //temp = (a * b) / gcdofAB;

        lint c = factorize(a, b, L);     //find the minimum possible value of c

        if(L % a != 0 || L % b != 0)            //if the value of c is greater than lcm(a, b, c)
            printf("Case %d: impossible\n", cases++);
        else
            printf("Case %d: %lld\n", cases++, c);
    }

    return 0;
}
