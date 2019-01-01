// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;

    cin>>n;

    n = n + 1;
    if(n == 1){
        cout<<0<<endl;
        return 0;
    }
    int lg = (int)log2(n + 1);

    if(n % 2 == 0){
        cout<<n / 2<<endl;
    }
    else{
        cout<<n<<endl;
    }

    return 0;
}
