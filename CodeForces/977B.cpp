// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    char str[MAX], ch1, ch2;

    cin>>n;

    cin>>str;

    int len = strlen(str);

    int Max = -1;
    for(int i = 0; i < len - 1; i++){
        int cnt = 0;
        for(int j = 0; j < len - 1; j++){
            if(str[j] == str[i] && str[j+1] == str[i+1]){
                cnt++;
            }
        }
        if(cnt > Max){
            Max = cnt;
            ch1 = str[i];
            ch2 = str[i+1];
        }
    }

    cout<<ch1<<ch2<<endl;


    return 0;
}
