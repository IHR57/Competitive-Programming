#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>str;

    for(int i = 0; i < 3; i++){
        if(str[i] == str[i+1]){
            cout<<"Bad"<<endl;
            return 0;
        }
    }

    cout<<"Good"<<endl;

    return  0;
}
