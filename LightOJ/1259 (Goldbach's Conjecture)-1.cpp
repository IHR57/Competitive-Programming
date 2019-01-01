#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define MAX 10000100
using namespace std;

int primes[700000];
bool mark[MAX];
int counter = 0;

int genSieve()
{
    int limit = sqrt(MAX + 1);

    mark[1] = 1;

    for(int i = 4; i < MAX; i += 2){
        mark[i] = 1;
    }

    primes[counter++] = 2;      //2 is first and only even prime number

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){     //sqrt(MAX)
                for(int j = i * i; j < MAX; j += i * 2){
                    mark[j] = 1;
                }
            }
        }
    }
}

int main()
{
    genSieve();

    int test, cases = 1, n, first, last;

    scanf("%d", &test);     //number of test case

    while(test--){
        scanf("%d", &n);            //n must be even number

        for(int i = 0; primes[i] <= n; i++)
            last = i;       // index of last prime less than or equal n
        first = 0;  //index of first prime
        int count = 0;
        while(first <= last){
            if(primes[first] + primes[last] == n){
                first++;
                last--;
                count++;
            }
            else if(primes[first] + primes[last] > n){
                last--;
            }
            else if(primes[first] + primes[last] < n)
                first++;
        }
        /*if(first == last){
            if(primes[first] + primes[last] == n)
                count++;
        }*/

        printf("Case %d: %d\n", cases++, count);
    }

    return 0;
}
