//Problem ID: CodeForces - 151C (Win or Freeze)
//Programmer: IQBAL HOSSAIN     Description: Number Theory
//Date: 09/01/19
#include <bits/stdc++.h>
#define MAX 4000005
using namespace std;

typedef long long ll;

ll primes[MAX/10], counter = 0;
bool mark[MAX];

void genSieve()
{
    int limit = sqrt(MAX + 1);

    mark[1] = true;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = true;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i++){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2){
                    mark[j] = 1;
                }
            }
        }
    }
}

void solve(ll n)
{
    ll idx = 0, pf = primes[idx], q = n;
    vector<ll> v;

    while(pf * pf <= n){
        if(n % pf == 0){
            while(n % pf == 0){
                v.push_back(pf);
                n /= pf;
            }
        }
        pf = primes[++idx];
    }
    if(n != 1){
        v.push_back(n);
    }

    if(v.size() == 1){
        printf("1\n");
        printf("0\n");
    }
    else if(v.size() == 2){
        printf("2\n");
    }
    else{
        ll temp = 1;
        for(int i = 0; i < v.size() - 2; i++){
            temp *= v[i];
        }
        printf("1\n");
        printf("%lld\n", q/temp);
    }
}

int main()
{
    genSieve();
    ll q;

    scanf("%lld", &q);

    if(q == 1){
        printf("1\n0\n");
        return 0;
    }

    solve(q);

    return 0;
}
