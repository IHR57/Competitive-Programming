#include <iostream>
#include <string.h>
using namespace std;

bool check(char* str)
{
    int count = 0;
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if(str[i] == '1')
            count++;
    }

    if(count == len)
        return true;

    return false;
}

int main()
{
    int n, d, count = 0, Max = 0;
    char str[200];

    cin>>n>>d;

    for(int i = 1; i <= d; i++){
        cin>>str;
        if(!check(str)){
            count++;
        }
        if(check(str))
            count = 0;
        if(count >= Max)
            Max = count;
    }

    cout<<Max<<endl;

    return 0;
}
