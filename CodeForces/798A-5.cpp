#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    char str[50], temp1[50], temp2[50];

    cin>>str;

    int len = strlen(str);

    int count = 0;
    for(int i = 0, j = len-1; i < len / 2; i++, j--){
        if(str[i] != str[j])
            count++;
    }


    if(count == 0 && len % 2 != 0)
        cout<<"YES"<<endl;
    else if(count == 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
