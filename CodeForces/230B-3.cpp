#include <bits/stdc++.h>
#define MAX 1000100
using namespace std;

typedef long long ll;

int mark[MAX], primes[MAX/10], counter = 0;
ll arr[MAX];

void genSieve()
{
    int limit = sqrt(MAX) + 1;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;

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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    genSieve();

    set<ll> s;

    for(int i = 0; i < counter; i++){
        ll mul = ((ll) primes[i] * (ll) primes[i]);
        if(mul <= 1000000000000){
            s.insert(mul);
        }
    }

    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        if(s.find(arr[i]) != s.end()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
