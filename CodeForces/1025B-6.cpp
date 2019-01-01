// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 150005
using namespace std;

typedef long long ll;

int a[MAX], b[MAX], c[MAX], d[MAX];

/*void genSieve()
{
    int limit = (int) sqrt(45000) + 1;

    mark[1] = 1;
    for(int i = 4; i < 45000; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;

    for(int i = 3; i < 45000; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < 45000; j += i * 2){
                    mark[j] = 1;
                }
            }
        }
    }
}*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //genSieve();

    ll n, div = 2, a, b;

    cin>>n;
    cin>>a>>b;
    set<ll> s;

    while(div * div <= a){
        if(a % div == 0){
            s.insert(div);
            while(a % div == 0)
                a /= div;
        }
        div++;
    }
    if(a > 1)
        s.insert(a);

    div = 2;
    while(div * div <= b){
        if(b % div == 0){
            s.insert(div);
            while(b % div == 0)
                b /= div;
        }
        div++;
    }
    if(b > 1)
        s.insert(b);

    for(int i = 1; i < n; i++){
        cin>>a>>b;
        vector<ll> v;
        for(set<ll>::iterator it = s.begin(); it != s.end(); it++){
            div = *it;
            if((a % div) && (b % div))
                v.push_back(div);
        }
        for(int j = 0; j < v.size(); j++){
            s.erase(v[j]);
        }
    }

    if(s.size()){
        cout<<*s.begin()<<endl;
    }
    else
        cout<<-1<<endl;

    return 0;
}
