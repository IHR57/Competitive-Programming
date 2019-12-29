//Problem ID: AtCoder - abc120_c (Unification)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 03/06/19
//Problem Link: https://atcoder.jp/contests/abc120/tasks/abc120_c
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
    string str;

    cin>>str;

    int len = str.size(), ans = 0;
    set<int> s;

    int i = 0, j = 1;
    while(true){
        if(i >= len || j >= len)
            break;
        if(str[i] == str[j] || i < 0){
            if(i >= 0)
                s.insert(i);
            i = j;
            j = j + 1;
        }
        else{
            if(s.count(i)){
                s.erase(i);
            }
            if(!s.empty()){
                i = *s.rbegin();
            }
            else
                i = -1;
            j++;
            ans += 2;
        }
    }

    cout<<ans<<endl;

    return 0;
}