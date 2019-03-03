#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll Power(int a, int b)
{
    ll result = 1;
    for(int i = 1; i <= b; i++){
        result *= a;
    }

    return result;
}

int sumofDigit(int n)
{
    int sum = 0;
    while(n != 0){
        sum += (n % 10);
        n /= 10;
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b, c;

    cin>>a>>b>>c;

    set<ll> s;
    for(int i = 1; i <= 81; i++){
        //for(int j = 1; j <= 5; j++){
            ll temp = b * Power(i, a) + c;
            if(temp > 0 && temp < 1000000000 && sumofDigit(temp) == i){
                s.insert(temp);
            }
        //}
    }

    cout<<s.size()<<endl;

    for(set<ll>::iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
