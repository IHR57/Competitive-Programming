#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll test, n;

    cin>>test;

    while(test--){
        cin>>n;
        ll ans;
        if(n % 4 == 0 || n % 4 == 2){
            ans = 4 * n + 1;
        }
        else if(n % 4 == 1)
            ans = 2 * n + 1;
        else
            ans = n + 1;
        cout<<ans<<endl;
    }

    return 0;
}
