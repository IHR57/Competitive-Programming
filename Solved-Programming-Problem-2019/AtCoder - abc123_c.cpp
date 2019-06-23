//Problem ID: AtCoder - abc123_c (Five Transportations)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 30/05/19
//Problem Link: https://atcoder.jp/contests/abc123/tasks/abc123_c
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ll n, m;
    ll Min = 1e18;
    cin>>n;
    int idx;
    for(int i = 1; i <= 5; i++){
        cin>>m;
        if(m < Min){

            Min = m;
            idx = i;
        }
    }

    if(Min >= n){
        cout<<5<<endl;
        return 0;
    }
    ll temp;
    if(n % Min == 0)
        temp = n / Min;
    else
        temp = (n / Min) + 1;
    ll ans = (idx + temp - 1);
    ans += 5 - idx;

    cout<<ans<<endl;

    return 0;
}