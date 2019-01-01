#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
const ll inf = 1e12;

ll countSetBit(ll n)
{
    ll cnt = 0;
    while(n){
        n &= (n - 1);
        cnt++;
    }

    return cnt;
}

ll Power(ll n, ll k)
{
    ll result = 1;
    for(ll i = 1; i <= k; i++){
        result *= n;
    }

    return result;
}

ll calculate(ll a[], ll n)
{
    ll sum = 0;
    ll j = n - 1;
    for(ll i = 0; i < n; i++){
        sum += (a[i] * Power(10, j));
        j--;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll arr[20], n;

    cin>>n;

    ll t = n;

    ll j = 0, digit = 0;
    while(n > 0){
        arr[j++] = n % 10;
        digit++;
        n /= 10;
    }

    ll Min = inf;

    for(ll mask = 1; mask < (1<<(digit)); mask++){
        ll temp = countSetBit(mask);
        if(temp == digit / 2){
            for(ll k = 0; k < digit; k++){
                if((mask & (1<<k)) == 0){
                    arr[k] = 4;
                }
                else
                    arr[k] = 7;
            }
            ll result = calculate(arr, digit);
            if(result >= t){
                if(result < Min){
                    Min = result;
                    //cout<<Min<<endl;
                }
            }
        }
    }
    //cout<<Min<<endl;
    if(digit % 2 != 0 || Min == inf){
        for(ll i = 0; i <= digit / 2; i++)
            cout<<"4";
        for(ll i = 0; i <= digit / 2; i++)
            cout<<"7";
        cout<<endl;
        return 0;
    }

    cout<<Min<<endl;

    return 0;
}
