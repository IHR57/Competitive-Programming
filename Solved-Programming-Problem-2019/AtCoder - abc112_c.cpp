//Problem ID: AtCoder - abc112_c (Pyramid)
//Programmer: IQBAL HOSSAIN     Description: Brute Force/MATH
//Date: 06/07/19
//Problem Link: https://atcoder.jp/contests/abc112/tasks/abc112_c
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int x[MAX], y[MAX], h[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>x[i]>>y[i]>>h[i];
    }

    int X, Y, H;

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            H = abs(i - x[1]) + abs(j - y[1]) + h[1]; 
            for(int k = 1; k <= n; k++){
                if(h[k] > 0){
                    H = h[k] + abs(i - x[k]) + abs(j - y[k]);
                    break;
                }
            }
            bool flag = true;
            for(int k = 1; k <= n; k++){
                int temp = max(0, H - abs(x[k] - i) - abs(y[k] - j));
                if(temp != h[k]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<i<<" "<<j<<" "<<H<<endl;
                return 0;
            }
        }
    }

    return 0;
}