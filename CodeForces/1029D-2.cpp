#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

ll n, k, arr[MAX], Power[11], len[MAX];
vector<ll> v[11];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n>>k;

    Power[0] = 1;
    for(int i = 1; i < 11; i++){
        Power[i] = (Power[i-1] * 10) % k;
    }

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        ll temp = arr[i];

        while(temp > 0){
            len[i]++;
            temp /= 10;
        }
        v[len[i]].push_back(arr[i] % k);
    }

    for(int i = 0; i < 11; i++){
        sort(v[i].begin(), v[i].end());
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < 11; j++){
            ll rem = (arr[i] * Power[j]) % k;
            ll t = (k - rem) % k;

            ll l = upper_bound(v[j].begin(), v[j].end(), t) - v[j].begin();
            ll r = lower_bound(v[j].begin(), v[j].end(), t) - v[j].begin();

            sum += (l - r);

            if(len[i] == j && (rem + arr[i] % k) % k == 0)          //exclude same pair (i, i)
                sum--;
        }
    }

    cout<<sum<<endl;

    return 0;

}
