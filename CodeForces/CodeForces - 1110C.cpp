//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 8000
using namespace std;

typedef long long ll;

int primes[1000];
int mark[8000];
int counter = 0;

void genSieve()
{
    int limit = sqrt(MAX + 1);
    mark[1] = 1;
    for(int i =4 ; i < MAX; i += 2){
        mark[i] = 1;
    }
    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
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

int factorize(int n)
{
    int idx = 0, pf = primes[idx];
    vector<int> ans;

    while(pf * pf <= n){
        if(n % pf == 0){
            while(n % pf == 0){
                n /= pf;
            }
            ans.push_back(pf);
        }
        pf = primes[++idx];
    }

    if(n != 1){
        ans.push_back(n);
    }

    return ans[0];
}
int solve(int n)
{
    int cnt = 0;
    while(n){
        n /= 2;
        cnt++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, n;

    genSieve();

    cin>>q;

    for(int i = 0; i < q; i++){
        cin>>n;
        int k = solve(n);

        if(((1<<k) - 1) == n){
           int temp = factorize(n);
           cout<<n / temp<<endl;
        }
        else{
            cout<<((1<<k) - 1)<<endl;
        }
    }


    return 0;
}

