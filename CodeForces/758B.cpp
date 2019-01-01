#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main()
{
    char str[200];
    char ch;

    cin>>str;
    int count = 0;

    int red, blue, yellow, green;
    int len = strlen(str);

    for(int i = 0; i < 4; i++){
        count = 0;
        for(int j = i; j < len; j += 4){
            if(str[j] == '!')
                count++;
            if(str[j] >= 'A' && str[j] <= 'Z')
                ch = str[j];
        }

        if(ch == 'R'){
            red = count;
        }
        else if(ch =='B')
            blue = count;
        else if(ch == 'Y')
            yellow = count;
        else if(ch == 'G')
            green = count;
    }
    cout<<red<<" "<<blue<<" "<<yellow<<" "<<green<<endl;

    return 0;
}
