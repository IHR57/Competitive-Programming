#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, sum;

    cin>>n;

    if(n == 1){
        cout<<1<<endl;
        return 0;
    }

    sum = 0;
    for(int i = n; i >= 1; i--){
        sum += (i + (i - 1) * (n - i));
    }

    cout<<sum<<endl;

    return 0;
}
