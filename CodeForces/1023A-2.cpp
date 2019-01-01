// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    string s, t;

    cin>>n>>m;
    cin>>s;
    cin>>t;

    if(n > m + 1){
        cout<<"NO"<<endl;
        return 0;
    }
    int flag = 0, idx;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '*'){
            flag = 1;
            idx = i;
        }
    }

    if(!flag){
        if(s == t){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        int flag1 = 1, flag2 = 1;
        for(int i = 0; i < idx; i++){
            if(s[i] != t[i]){
                flag1 = 0;
                break;
            }
        }
        int j = (int) t.size() - 1;
        for(int i = (int) s.size() - 1; i > idx; i--){
            if(s[i] != t[j]){
                //cout<<s[i]<<" "<<t[j]<<endl;
                flag2 = 0;
                break;
            }
            j--;
        }

        //cout<<flag1<<" "<<flag2<<endl;
        if(flag1 && flag2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
