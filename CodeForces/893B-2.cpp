// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int Power(int a, int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return a;
    if(n % 2 == 1)
        return a * Power(a, n - 1);
    int temp;
    temp = Power(a, n / 2);

    return temp * temp;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    vector<ll> divisor;

    cin>>n;

    int k = 0;
    for(int i = 1; i <= n / 2; i++){
        if(n % i == 0){
            divisor.push_back(i);
        }
    }

    divisor.push_back(n);

    sort(divisor.begin(), divisor.end());
    reverse(divisor.begin(), divisor.end());

    int result = n;

    int flag = 0;
    for(int i = 0; i < divisor.size(); i++){
        for(int k = 1; k <= 20; k++){
            ll v1 = (ll) Power(2, k) - 1;
            ll v2 = (ll) Power(2, k - 1);
            if(v1 * v2 == divisor[i]){
                result = divisor[i];
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }

    cout<<result<<endl;

    return 0;
}
