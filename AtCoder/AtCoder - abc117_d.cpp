//Problem ID: AtCoder - abc117_d (XXOR)
//Programmer: IQBAL HOSSAIN     Description: Bit
//Date: 10/06/19
//Problem Link: https://atcoder.jp/contests/abc117/tasks/abc117_d
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
int cnt[45];
ll arr[MAX];

bool check(ll mask, ll pos){return (bool)(mask & (1LL<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ll n, k;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        for(int j = 0; j <= 40; j++){
            if(check(arr[i], j))
                cnt[j]++;
        }
    }

    ll lg = (int) log2(k), temp = 0;

    for(int i = 40; i >= 0; i--){
        if(cnt[i] * 2 < n){
            ll t = (1LL << i);
            if(temp + t <= k)
                temp += t;
        }
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum = (sum + (arr[i] ^ temp));
    }

    cout<<sum<<endl;
    
    return 0;
}
