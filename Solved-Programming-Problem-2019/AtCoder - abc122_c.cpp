//Problem ID: AtCoder - abc122_c (Get AC)
//Programmer: IQBAL HOSSAIN     Description: String
//Date: 01/06/19
//Problem Link: https://atcoder.jp/contests/abc122/tasks/abc122_c
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    string str;
    int n, q, l, r;

    cin>>n>>q;
    cin>>str;

    for(int i = 1; i < n; i++){
        if(str[i] == 'C' && str[i-1] == 'A'){
            cs[i+1] = cs[i] + 1;
        }
        else{
            cs[i+1] = cs[i];
        }
    }

    for(int i = 0; i < q; i++){
        cin>>l>>r;
        cout<<cs[r] - cs[l]<<endl;
    }

    return 0;
}