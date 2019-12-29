//Problem ID: LightOJ - 1236 (Pairs Forming LCM)
//Programmer: IQBAL HOSSAIN     Description: Number Theory
//Date: 20/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1236
#include <bits/stdc++.h>
#define MAX 10000005
using namespace std;

typedef long long ll;

bool mark[MAX];
vector<int> primes;

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

ll solve(ll n)
{
    int pf, sq = sqrt((double) n);
    ll cnt, ans = 1;

    int v = primes.size();

    for(int i = 0; i < v && primes[i] <= sq; i++){
        pf = primes[i];
        if(n % pf == 0){
            cnt = 0;
            while(n % pf == 0){
                n /= pf;
                cnt++;
            }
            ans *= (2 * cnt + 1);
            sq = sqrt((double) n);
        }
    }
    if(n > 1){
        ans *= 3;
    }

    return (ans / 2) + 1;
}

int main()
{
    genSieve();
//    cout<<primes.size()<<" "<<primes[primes.size()-1]<<endl;
    int test, caseno = 1;
    ll n;

    scanf("%d", &test);

    while(test--){
        scanf("%lld",  &n);
        ll result = solve(n);

        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
