//Problem ID: Toph - Playing with Your Mind
//Programmer: IQBAL HOSSAIN     Description: Number Theory
//Date: 21/05/19
//Problem Link: https://toph.co/p/playing-with-your-mind
#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

typedef long long ll;

ll solve(ll n)
{
    while(n % 2 == 0){
        n /= 2;
    }

    return n;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, caseno = 1;
    ll n;
    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        if(n % 2){
            printf("Case %d: %lld\n", caseno++, n);
        }
        else{
            printf("Case %d: %lld\n", caseno++, solve(n));
        }
    }

    return 0;
}