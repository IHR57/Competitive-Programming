//Problem ID: AtCoder - abc127_c
//Programmer: IQBAL HOSSAIN     Description: Math
//Date: 28/05/19
//Problem Link: https://atcoder.jp/contests/abc127/tasks/abc127_c

#include <bits/stdc++.h>
#define MAX 100005
#define read (freopen("input.txt", "r", stdin));
#define write (freopen("output.txt", "w", stdout));

using namespace std;

int main()
{
    //read; write;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l, r, m;

    cin>>n>>m;

    int Min = 1e9, Max = 0;
    for(int i = 0; i < m; i++){
        cin>>l>>r;
        Max = max(Max, l);
        Min = min(Min, r);
    }

    if(Max > Min){
        cout<<0<<endl;
    }
    else{
        cout<<Min - Max + 1<<endl;
    }

    return 0;
}