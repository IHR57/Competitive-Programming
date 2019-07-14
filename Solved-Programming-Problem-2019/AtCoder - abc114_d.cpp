//Problem ID: AtCoder - abc114_d
//Programmmer: IQBAL HOSSAIN    Description: Number Theory
//Date: 28/06/19
//Problem Link: https://atcoder.jp/contests/abc114/tasks/abc114_d
#include <bits/stdc++.h>
#define MAX 100005
#define EPS 1e-8
using namespace std;

typedef long long ll;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int factor[105];

void factorize(int n)
{
    int idx = 0, pf = primes[idx];
    while(pf * pf <= n){
        if(n % pf == 0){
            while(n % pf == 0){
                factor[pf]++;
                n /= pf;
            }
        }
        pf = primes[++idx];
    }
    if(n != 1)
        factor[n]++;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n;

    cin>>n;

    for(int i = 2; i <= n; i++){
        factorize(i);
    }
    
    int cnt = 0;
    for(int i = 0; i < 25; i++){
        if(factor[i] >= 74)
            cnt++;
        for(int j = i + 1; j < 25; j++){
            if(factor[primes[i]] >= 2 && factor[primes[j]] >= 24)
                cnt++;
            if(factor[primes[i]] >= 24 && factor[primes[j]] >= 2)
                cnt++;
            if(factor[primes[i]] >= 4 && factor[primes[j]] >= 14)
                cnt++;
            if(factor[primes[i]] >= 14 && factor[primes[j]] >= 4)
                cnt++;
            for(int k = j + 1; k < 25; k++){
                if(factor[primes[i]] >= 4 && factor[primes[j]] >= 4 && factor[primes[k]] >= 2)
                    cnt++;
                if(factor[primes[i]] >= 4 && factor[primes[j]] >= 2 && factor[primes[k]] >= 4)
                    cnt++;
                if(factor[primes[i]] >= 2 && factor[primes[j]] >= 4 && factor[primes[k]] >= 4)
                    cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    

    return 0;
}