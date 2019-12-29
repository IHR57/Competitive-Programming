//Problem ID: AtCoder - abc110_c (String Transformation)
//Programmer: IQBAL HOSSAIN     Description: Sorting
//Date: 13/07/19
//Problem Link: https://atcoder.jp/contests/abc110/tasks/abc110_c
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

int cnt1[30], cnt2[30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt",  "w", stdout);
    #endif
    string s, t;

    cin>>s>>t;
    int n = s.size();

    for(int i = 0; i < n; i++){
        cnt1[s[i]-'a']++;
        cnt2[t[i]-'a']++;
    }    

    sort(cnt1, cnt1 + 26);
    sort(cnt2, cnt2 + 26);

    for(int i = 0; i < 26; i++){
        if(cnt1[i] != cnt2[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;

    return 0;
}