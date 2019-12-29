//Problem ID: LightOJ - 1278 (Sum of Consecutive Integers)
//Programmer: IQBAL HOSSAIN     Description: Number Theory
//Date: 21/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1278
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX 10000020
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

bool mark[MAX];
vector<int> primes;
vector<ll> divisors;
vector<pii> factors;

void genSieve()
{
    int limit = sqrt(MAX);
    mark[1] = true;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = true;

    primes.push_back(2);

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes.push_back(i);
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2){
                    mark[j] = true;
                }
            }
        }
    }
}

void primeFactors(ll n)
{
    int idx = 0;
    ll pf = (ll) primes[idx], ans = 1;

    while(pf * pf <= n){
        int cnt = 0;
        while(n % pf == 0){
            cnt++;
            n /= pf;
        }
        if(cnt > 0)
            factors.push_back(make_pair(pf, (ll) cnt));
        pf = (ll) primes[++idx];
    }
    if(n > 1){
        factors.push_back(make_pair(n, 1));
    }
}

void setDivisors(ll n, int i)
{
    ll x;
    int j, k;
    for(j = i; j < factors.size(); j++){
        x = factors[j].first * n;
        for(k = 0; k < factors[j].second; k++){
            divisors.push_back(x);
            setDivisors(x, j + 1);
            x *= factors[j].first;
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    genSieve();
    ll n;
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);

        factors.clear();
        divisors.clear();

        primeFactors(n);
        setDivisors(1, 0);

        divisors.push_back(1);
//        sort(divisors.begin(), divisors.end());
//        for(int i = 0; i < divisors.size(); i++){
//            cout<<divisors[i]<<" ";
//        }
//        cout<<endl;

        int cnt = 0;
        for(int i = 0; i < divisors.size(); i++){
            ll temp = n / divisors[i];
            if(temp % 2){
                cnt++;
            }
        }

        printf("Case %d: %d\n", caseno++, cnt-1);
    }

    return 0;
}
