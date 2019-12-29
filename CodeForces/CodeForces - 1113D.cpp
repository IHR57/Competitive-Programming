//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

string str;

bool isPalin(string s)
{
    int len = (int) s.length();
    for(int i = 0; i < len / 2; i++){
        if(s[i] != s[len-i-1]){
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>str;

    int len = (int) str.length();

    int cnt = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == str[0]){
            cnt++;
        }
    }

    if(len % 2 == 0){
        if(cnt == len){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    if(len % 2 != 0){
        if(cnt == len || cnt == len - 1){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }

    string temp = str;
    for(int i = 0; i < len; i++){
        temp = temp[len-1] + temp;
        temp.erase(temp.begin() + len);
        //cout<<temp<<endl;
        if(temp != str){
            if(isPalin(temp)){
                cout<<"1"<<endl;
                return 0;
            }
        }
    }
    cout<<"2"<<endl;

    return 0;
}
