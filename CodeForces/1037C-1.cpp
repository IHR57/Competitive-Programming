// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

string str1, str2;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    cin>>str1>>str2;

    int len = (int) str1.length();

    int cnt = 0;

    for(int i = 0; i < len - 1; i++){
        if(str1[i] != str2[i] && str1[i+1] != str2[i+1] && str1[i] == str2[i+1] && str1[i+1] == str2[i]){
            swap(str1[i], str1[i+1]);
            cnt++;
        }
    }

    //cout<<str1<<" "<<str2<<endl;

    for(int i = 0; i < len; i++){
        if(str1[i] != str2[i]){
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
