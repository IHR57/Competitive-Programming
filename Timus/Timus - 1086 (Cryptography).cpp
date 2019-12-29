//Problem ID: TIMUS - 1086 (Cryptography)
//Programmer: IQBAL HOSSAIN     Description: Number Theory
//Date: 19/07/19
#include <bits/stdc++.h>
#define MAX 2500005
using namespace std;

typedef long long ll;

bool mark[MAX];
vector<int> primes;

void genSieve()
{
    int limit = sqrt(MAX);
    mark[1] = 1;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;
    primes.push_back(2);

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes.push_back(i);
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt",  "w", stdout);
    #endif
    genSieve();

    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        cout<<primes[n-1]<<endl;
    }
    
    return 0;
}
