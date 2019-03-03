#include <bits/stdc++.h>
#define MAX 1500005
using namespace std;

bool mark[MAX];
int primes[MAX], counter = 0;

void genSieve()
{
    int limit = sqrt(MAX) + 1;
    mark[1] = true;

    for(int i = 4; i < MAX; i += 2)
        mark[i] = true;

    primes[counter++] = 2;
    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    genSieve();

    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<primes[i]<<" ";
    }
    cout<<endl;

    return 0;
}
