//Problem ID: AtCoder - abc126_c (Dice and Coin)
//Programmer: IQBAL HOSSAIN     Description: Implementation/MATH
//Date: 29/05/19
#include <bits/stdc++.h>
#define MAX 5005
using namespace std;

int n, k;

int lg(int x)
{
    int cnt = 0;
    while(x < k){
        cnt++;
        x = x * 2;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cin>>n>>k;

    double sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (1 / (double) n) * (1 / (double) (1 << lg(i)));
    }

    cout<<setiosflags(ios::fixed)<<setprecision(12);
    cout<<sum<<endl;

    return 0;
}