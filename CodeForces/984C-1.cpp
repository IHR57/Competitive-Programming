// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll p, q, b;
    int test;

    cin>>test;

    while(test--){
        cin>>p>>q>>b;
        if((__gcd(p, q) == 1 && q != 1)){
            cout<<"Infinite"<<endl;
        }
        else{
            cout<<"Finite"<<endl;
        }
    }

    return 0;
}
