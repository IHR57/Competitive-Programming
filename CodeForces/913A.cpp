// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;

    cin>>n>>m;

    if(n >= 31){
        cout<<m<<endl;
    }
    else{
        cout<<m % (1<<n)<<endl;
    }

    return 0;
}
