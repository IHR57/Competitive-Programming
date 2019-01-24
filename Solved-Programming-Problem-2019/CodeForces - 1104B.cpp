//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>str;

    int len = (int) str.size();
    stack<char> s;

    int ans = 0, lastPos = 0;
    for(int i = 0; i < len; i++){
        if(!s.empty() && str[i] == s.top()){
            s.pop();
            ans++;
        }
        else{
            s.push(str[i]);
        }
    }

    if(ans % 2 == 0){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }

    return 0;
}
