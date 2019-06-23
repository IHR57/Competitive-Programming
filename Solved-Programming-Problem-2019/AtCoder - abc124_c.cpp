//Problem ID: AtCoder - abc124_c (Coloring Colorfully)
//Programmer: IQBAL HOSSAIN         Description: String
//Date: 30/05/19
//Problem Link: https://atcoder.jp/contests/abc124/tasks/abc124_c
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cin>>str;

    int Min = 1e8, cnt = 0, flag = 0;
    int len = str.size();

    for(int i = 0; i < len; i++){
        if(!flag){
            if(str[i] == '1')
                cnt++;
            flag = 1;
        }
        else{
            if(str[i] == '0')
                cnt++;
            flag = 0;
        }
    }

    Min = min(Min, cnt);
    cnt = 0, flag = 1;

    for(int i = 0; i < len; i++){
        if(!flag){
            if(str[i] == '1')
                cnt++;
            flag = 1;
        }
        else{
            if(str[i] == '0')
                cnt++;
            flag = 0;
        }
    }
    Min = min(Min, cnt);

    cout<<Min<<endl;

    return 0;
}