#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 5000005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], n;

int countInversion(int a[])
{
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j])
                cnt++;
        }
    }

    return cnt;
}

ll powMod(ll a, ll b)
{
    ll res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll k;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int cnt1 = countInversion(arr);
    reverse(arr, arr + n);
    int cnt2 = countInversion(arr);
    ll d = 1LL * (cnt1 + cnt2);
    ll a = cnt1;

    ll temp = ((2 * a) % MOD + ((k - 1) * d) % MOD) % MOD;
    temp = (temp * k) % MOD;
    temp = temp * powMod(2, MOD - 2);

    cout<<temp % MOD<<endl;

    return 0;
}
