//Problem ID: CodeForces - 1137B (Camp Schedule)
//Programmer: IQBAL HOSSAIN     Description: Greedy/Hashing
//Date: 30/05/19
#include <bits/stdc++.h>
#define MAX 500005
using namespace std;

string s, t;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int cnt0 = 0, cnt1 = 0;

    cin>>s>>t;

    int len = s.size();
    for(int i = 0; i < len; i++){
        (s[i] == '0') ? cnt0++ : cnt1++;
    }

    len = t.size();
    for(int i = 0; i < len; i++){
        (t[i] == '0') ? cnt0-- : cnt1--;
    }
    if(len == 1 || cnt0 < 0 || cnt1 < 0){
        cout<<s<<endl;
        return 0;
    }

    int idx = 0;
    for(int i = 1; i < len; i++){
        if(t[i] == t[idx]){
            idx++;
        }
        else{
            idx = 0;
            if(t[i] == t[idx])
                idx++;
        }
    }
    string res = t;
    while(true){
        bool flag = 0;
        for(int i = idx; i < len; i++){
            if(t[i] == '1'){
                if(cnt1 <= 0){
                    flag = 1;
                    break;
                }
                res += "1";
                cnt1--;
            }
            else{
                if(cnt0 <= 0){
                    flag = 1;
                    break;
                }
                res += "0";
                cnt0--;
            }
        }
        if(flag)
            break;
    }
    for(int i = 0; i < cnt1; i++)
        res += "1";
    for(int i = 0; i < cnt0; i++)
        res += "0";

    cout<<res<<endl;

    return 0;
}