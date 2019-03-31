#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

vector<ll> divisors;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k;

    cin>>n>>k;

    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            divisors.push_back(i);
            if((n / i) != i)
                divisors.push_back(n / i);
        }
    }

    sort(divisors.begin(), divisors.end());

    if(k > divisors.size()){
        cout<<-1<<endl;
        return 0;
    }

    cout<<divisors[k-1]<<endl;

    return 0;
}
