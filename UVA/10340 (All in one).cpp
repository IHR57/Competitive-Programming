#include <iostream>
#include <string.h>
#define LENGTH 5000000
using namespace std;

char s[LENGTH], t[LENGTH];

bool CheckSubStr()
{
    int s_len, t_len;

    s_len=strlen(s);
    t_len=strlen(t);
    int i, count=0;

    for(i=0; i<t_len; i++){
        if(s[count]==t[i]){
            ++count;
            if(count>=s_len)
                return true;
        }
    }
    return false;
}

int main()
{
    while(cin>>s>>t){
        if(CheckSubStr())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
