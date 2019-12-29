//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

string temp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    int one = 0;

    cin>>str;
    int len = (int) str.length();

    for(int i = 0; i < len; i++){
        if(str[i] == '1')
            one++;
        else
            temp += str[i];
    }

    int n = (int) temp.length();

    int flag = 1;
    for(int i = 0; i < n; i++){
        if(temp[i] != '0' && flag){
            for(int j = 0; j < one; j++){
                cout<<"1";
            }
            flag = 0;
            cout<<temp[i];
        }
        else{
            cout<<temp[i];
        }
    }
    if(flag){
        for(int i = 0; i < one; i++){
            cout<<"1";
        }
    }
    cout<<endl;

    return 0;
}
