//Problem ID: AtCoder - abc109_c.cpp
//Programmer: IQBAL HOSSAIN     Description: Number Theory
//Date: 12/07/19
//Problem Link: https://atcoder.jp/contests/abc109/tasks/abc109_c
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, x, val;

    cin>>n>>x;

    cin>>val;
    int g = abs(val - x);

    for(int i = 2; i <= n; i++){
        cin>>val;
        g = __gcd(g, abs(val - x));
    }

    cout<<g<<endl;

    return 0;
}