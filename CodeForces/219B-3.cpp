#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll Power(int k)
{
    ll result = 1;

    for(int i = 1; i <= k; i++){
        result *= 10;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, d, result;

    cin>>n>>d;

    result = n;

    ll t = n;

    int count = 0;
    bool flag = true;
    while(t != 0){
        if(t % 10 == 9 && flag)
            count++;
        else{
            flag = false;
        }
        t /= 10;
    }

    for(int k = count + 1; k <= 20; k++){
        ll temp = (n - (n % Power(k)) - 1);
        if(n - temp <= d && temp != -1){
            result = temp;
        }
        else{
            break;
        }
    }

    cout<<result<<endl;
}
