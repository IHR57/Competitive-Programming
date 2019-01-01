#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int before, after, n, flag = 0;
    char str[50];

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>str>>before>>after;
        if(before >= 2400 && after > before)
            flag = 1;
    }

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
