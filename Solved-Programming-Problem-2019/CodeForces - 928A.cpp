//Problem ID: CodeForces - 928A (Login Verification)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 30/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

set<string> s;

string change(string str)
{
    int len = str.size();
    for(int i = 0; i < len; i++){
        if(str[i] == '1' || str[i] == 'l' || str[i] == 'I' || str[i] == 'i' || str[i] == 'L'){
            str[i] = '*';
        }
        if(str[i] == 'O' || str[i] == '0' || str[i] == 'o')
            str[i] = '#';
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = char(str[i] - 65 + 97);
            //cout<<str[i]<<endl;
        }
    }
    return str;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str, tstr;

    cin>>str;
    str = change(str);
    int n;

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>tstr;
        tstr = change(tstr);
        s.insert(tstr);
    }

    if(s.count(str)){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }

    return 0;

}
