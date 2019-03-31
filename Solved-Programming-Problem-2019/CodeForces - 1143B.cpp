//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int prod(int n)
{
    int ans = 1;
    while(n != 0){
        ans *= (n % 10);
        n /= 10;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ans;

    cin>>n;

    ans = prod(n);

    if(n <= 9){
        cout<<n<<endl;
        return 0;
    }
    ll p = 10;
    while(p <= n){
        if(n % p != (p - 1)){
            n -= (n % p) + 1;
            ans = max(ans, prod(n));
        }
        p *= 10;
    }


    cout<<ans<<endl;

    return 0;
}

