// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str1[100], str2[100];

    cin>>str1>>str2;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int flag = 0;
    cout<<str1[0];
    for(int i = 1; i < len1; i++){
        if(str1[i] < str2[0]){
            cout<<str1[i];
        }
        else{
            cout<<str2[0]<<endl;
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout<<str2[0]<<endl;
    }

    return 0;
}
