// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str[100];

    cin>>str;

    int len = strlen(str);

    int count = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == '1' || str[i] == '3' || str[i] == '5' || str[i] == '7' || str[i] == '9'){
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}
