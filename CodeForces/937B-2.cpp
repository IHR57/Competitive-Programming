#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int primes[35000], mark[35000], counter = 0;
int p, y;
typedef long long ll;

bool prime(int n)
{
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    int sqrtN = sqrt(n + 1);
    for(int i = 3; i <= sqrtN; i += 2){
        if(n % i == 0)
            return false;
    }
    return true;
}

void Sieve()
{
    int limit = sqrt(35005);
    mark[1] = 1;
    for(int i = 4; i < 35000; i += 2)
        mark[i] = 1;
    primes[counter++] = 2;

    for(int i = 3; i < 35000; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < 35000; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

bool solve(int n)
{
    int idx = 0, pf = primes[idx];
    while(pf * pf <= n){
        while(n % pf == 0){
            n /= pf;
            if(pf > p)
                return true;
            else
                return false;
        }
        pf = primes[++idx];
    }
    if(n != 1){
        if(n > pf)
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Sieve();

    cin>>p>>y;

    //int sqrtY = (int) sqrt(y + 1);

    for(int i = y; ; i--){
        if(i > p){
            if(prime(i) || solve(i)){
                cout<<i<<endl;
                return 0;
            }
        }
        else
            break;
    }

    cout<<-1<<endl;

    return 0;
}
