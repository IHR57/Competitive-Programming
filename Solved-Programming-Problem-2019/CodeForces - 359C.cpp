//Problem ID: CodeForces - 359C (Prime Number)
//Programmer: IQBAL HOSSAIN     Description: Mathematics
//Date: 07/02/19
//Problem Link: https://codeforces.com/problemset/problem/359/C
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll arr[MAX];

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b / 2);
    x = (x * x) % MOD;
    if(b % 2 == 1){
        x = (x * a) % MOD;
    }

    return x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, x;

    cin>>n>>x;

    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += arr[i];
    }


    int cnt = 0;
    vector<ll> v;

    for(int i = 0; i < n; i++){
        v.push_back(sum - arr[i]);
    }
    sort(v.rbegin(), v.rbegin());

    while(true){
        ll temp = v[v.size() - 1];
        int cnt = 0;

        while(v.size() > 0 && v[v.size() -1] == temp){
            cnt++;
            v.pop_back();
        }
        if(cnt % x == 0){
            for(int i = 0; i < (cnt / x); i++){
                v.push_back(temp + 1);
            }
        }
        else{
            temp = min(temp, sum);
            cout<<bigMod(x, temp) % MOD<<endl;
            return 0;
        }
    }

    return 0;
}
