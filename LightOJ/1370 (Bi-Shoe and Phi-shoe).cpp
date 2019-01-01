#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 1000010
using namespace std;

typedef long long lint;
int primes[70000], counter = 0;
bool mark[MAX];
int nextPrime[MAX];     //we will save the prime number which is  greater than i
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

int main()
{
    genSieve();

    int k = 0;
    for(int i = 1; i < MAX; i++){       //pre generate
        if(primes[k] > i)
            nextPrime[i] = primes[k];
        else{
            k = k + 1;      //if equal or less
            nextPrime[i] = primes[k];
        }
    }

    /*for(int i = 1; i <= 26; i++)
        cout<<nextPrime[i]<<" ";
    cout<<endl;*/

    int test, cases = 1, data[10005], n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        lint sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &data[i]);
            sum += nextPrime[data[i]];
        }

        printf("Case %d: %lld Xukha\n", cases++, sum);
    }

    return 0;
}
