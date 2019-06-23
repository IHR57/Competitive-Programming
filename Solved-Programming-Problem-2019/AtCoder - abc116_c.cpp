//Problem ID: AtCoder - abc116_c (Grand Garden)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 12/06/19
//Problem Link: https://atcoder.jp/contests/abc116/tasks/abc116_c
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int h[MAX], arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>h[i];
    }

    int k = 0;
    bool flag = false;
    while(true){
        flag = false;
        int f = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == h[i] && f)
                break;
            else if(arr[i] == h[i] && !f)
                continue;
            else if(arr[i] < h[i]){
                flag = true;
                f = 1;
                arr[i]++;
            }
        }
        k++;
        if(!flag)
            break;
    }

    cout<<(k-1)<<endl;

    return 0;
}
