#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;

int main()
{
    ll x, y, n, first, second, result;

    cin>>x>>y;
    cin>>n;

    if(x < 0){
        x = (MOD + x) % MOD;
    }
    if(y < 0){
        y = (MOD + y) % MOD;
    }
    if(y - x < 0){
        second = (MOD + y - x) % MOD;
    }
    else
        second = y - x;
    if(x - y < 0){
        first = (MOD + x - y) % MOD;
    }
    else
        first = x - y;

    if(n % 3 == 0 && (n / 3 ) % 2 == 0){
        cout<<first<<endl;
    }
    else if(n % 3 == 0 && (n / 3) % 2 != 0){
        cout<<second<<endl;
    }
    else if((n % 3 != 0) && (n / 3) % 2 == 0){
        if(n % 3 == 1)
            cout<<x<<endl;
        else
            cout<<y<<endl;
    }
    else{
        if(n % 3 == 1)
            cout<<(MOD - x) % MOD<<endl;
        else
            cout<<(MOD - y) % MOD<<endl;
    }

    return 0;
}
