//Problem ID: CodeForces - 122C (Lucky Sum)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 10/01/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

vector<ll> v;

ll Power(int n)
{
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= 10;
    }
    return ans;
}

int main()
{
    int l, r;

    for(int k = 1; k <= 10; k++){
        for(int i = 0; i < (1<<k); i++){
            ll arr[k+2];
            for(int j = 0; j < k; j++){
                arr[j] = 4;
            }
            for(int j = 0; j < k; j++){
                if(i & (1<<j)){
                    arr[j] = 7;
                }
            }
            ll num = 0;
            for(int j = 0; j < k; j++){
                num += arr[j] * Power(j);
            }
            v.push_back(num);
        }
    }

    sort(v.begin(), v.end());

    cin>>l>>r;

    int lIdx = lower_bound(v.begin(), v.end(), l) - v.begin();
    int rIdx = lower_bound(v.begin(), v.end(), r) - v.begin();

    ll sum = (v[lIdx] - l + 1) * v[lIdx];

    for(int i = lIdx + 1; i <= rIdx; i++){
        sum += (v[i] - v[i-1]) * v[i];
    }

    sum += (r - v[rIdx]) * v[rIdx];

    cout<<sum<<endl;

    return 0;
}
