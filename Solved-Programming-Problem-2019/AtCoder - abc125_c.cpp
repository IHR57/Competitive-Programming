//Problem ID: AtCoder - abc125_c (GCD on Blackboard)
//Programmer: IQBAL HOSSAIN     Description: Number Theory
//Date: 30/05/19
//Problem Link: https://atcoder.jp/contests/abc125/tasks/abc125_c
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[MAX], pref[MAX], suff[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    pref[0] = arr[0];
    for(int i = 1; i < n; i++){
        pref[i] = __gcd(pref[i-1], arr[i]);
    }
    suff[n-1] = arr[n-1];
    for(int i = n - 2; i >= 0; i--){
        suff[i] = __gcd(suff[i+1], arr[i]);
    }

    int Max = 0;
    Max = max(Max, suff[1]);
    Max = max(Max, pref[n-2]);

    for(int i = 1; i < n - 1; i++){
        Max = max(Max, __gcd(pref[i-1], suff[i+1]));
    }

    cout<<Max<<endl;

    return 0;
}