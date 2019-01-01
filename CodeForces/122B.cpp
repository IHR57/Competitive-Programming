#include <bits/stdc++.h>
#define MAX 60
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str[MAX];
    int four = 0, seven = 0;

    cin>>str;

    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if(str[i] == '4')
            four++;
        else if(str[i] == '7')
            seven++;
    }

    if(four == 0 && seven == 0)
        cout<<-1<<endl;
    else if(seven > four)
        cout<<7<<endl;
    else
        cout<<4<<endl;

    return 0;
}
