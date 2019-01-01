#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll sumofDigit(ll n)
{
    ll sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, low, high;

    cin>>n;

    low = sqrt(n) - 90;
    high = sqrt(n);

    ll result = -1;

    for(int i = (low < 1) ? 1 : low; i <= high; i++){
        if(n % i == 0 && sumofDigit(i) == n / i - i){
            result = i;
            break;
        }
    }

    cout<<result<<endl;

    return 0;
}
